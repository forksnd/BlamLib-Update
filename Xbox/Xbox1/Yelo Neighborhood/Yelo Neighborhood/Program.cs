﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;
using YeloDebug;
using System.Threading;
using System.Xml;
using System.IO;

namespace Yelo_Neighborhood
{
    static class Program
    {
        public static Xbox XBox { get { return _xbox; } }
        static Xbox _xbox;

        public static ScreenshotTool ScreenshotTool { get { return _screenshotTool; } }
        static ScreenshotTool _screenshotTool;

        public static XBoxLocator XBoxLocator { get { return _xboxLocator; } }
        static XBoxLocator _xboxLocator;

        public static List<Executable> Executables { get { return _executables; } }
        static List<Executable> _executables = new List<Executable>();

        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Control.CheckForIllegalCrossThreadCalls = false;
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);

            _xboxLocator = new XBoxLocator();
            _screenshotTool = new ScreenshotTool();

            LoadExecutables();

            if (Properties.Settings.Default.AutoDiscover) FindXBox();
            else FindXBox(Properties.Settings.Default.XBoxIP);
        }

        public static void LoadExecutables()
        {
            if (!File.Exists("Executables.xml"))
            {
                StreamWriter sw = File.CreateText("Executables.xml");
                sw.WriteLine("<Executables></Executables>");
                sw.Close();
            }
            XmlReader xr = XmlReader.Create(File.OpenRead("Executables.xml"));
            Executable workingExe = null;
            while (!xr.EOF)
            {
                xr.Read();
                switch (xr.Name)
                {
                    case "Executable":
                        if (xr.NodeType == XmlNodeType.EndElement) continue;
                        workingExe = new Executable() { Name = xr.GetAttribute("Name"), Filename = xr.GetAttribute("Filename") };
                        _executables.Add(workingExe);
                        break;
                    case "Script":
                        if (xr.NodeType == XmlNodeType.EndElement) continue;
                        Executable.Script script = new Executable.Script();
                        script.Name = xr.GetAttribute("Name");
                        script.FileType = xr.GetAttribute("FileType");
                        script.Code = xr.ReadInnerXml();
                        workingExe.Scripts.Add(script);
                        break;
                }
            }
        }

        private static void AsyncConnect(string xbox)
        { new Thread(new ParameterizedThreadStart(Connect)).Start(xbox); }

        private static void AsyncConnect()
        { new Thread(new ThreadStart(Connect)).Start(); }

        private static void Connect(object xbox)
        {
            try
            {
                _xbox.Connect((string)xbox);
                _xboxLocator.Hide();
            }
            catch
            { _xboxLocator.Hide(); }
        }

        private static void Connect()
        {
            try
            {
                _xbox.Connect();
                _xboxLocator.Hide();
            }
            catch
            { _xboxLocator.Hide(); }
        }

        public static void FindXBox()
        {
            _xbox = new Xbox();
            AsyncConnect();
            _xboxLocator.ShowDialog();

            if (XBox.Connected)
            {
                //MessageBox.Show(XBox.StreamTest());
                new Main().ShowDialog();
                XBox.Disconnect();
            }
            else new Settings().ShowDialog();
        }

        public static void FindXBox(string xbox)
        {
            _xbox = new Xbox();
            AsyncConnect(xbox);
            _xboxLocator.ShowDialog();

            if (XBox.Connected)
            {
                new Main().ShowDialog();
                XBox.Disconnect();
            }
            else new Settings().ShowDialog();
        }
    }
}