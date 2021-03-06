= OpenSauce for Halo Custom Edition v1.09 =
== Overview ==
Thank you for installing OpenSauce for Halo Custom Edition! You now have access to a plethora of features and extensions added to Halo Custom Edition which you can read all about on our Google Code wiki:
	http://code.google.com/p/open-sauce/wiki/

We have a WIP FAQ available for some of the more common questions that have been asked:
	http://code.google.com/p/open-sauce/wiki/Doc_Halo1_FAQ

It is still early days for OpenSauce so the way ahead may have a few bumps for some, but we hope they are minimal and that you enjoy it all the same!

== System Requirements ==
These requirements are mainly guesswork as we do not have the resources for broad testing on multiple hardware configurations.

Operating System: Microsoft Windows XP SP3, Microsoft Windows Vista SP2, Microsoft Windows 7 SP1
Computer/Processor: 1GHz processor.
DirectX: DirectX� 9.0c or later.
Memory: 512 megabytes (MB) of RAM.
Video card: 256 MB with shader model 2.a or 2.b, shader model 3.0 recommended.

You should not expect your current hardware to run Halo CE with OS at the same level of performace you had before. What OS adds does not come for free. If you feel that you would rather sacrifice some features for better performance, you can turn off various additions in the user settings file (see our Google code wiki for details).

== Installation ==
If you have cut and pasted or have otherwise moved your Halo CE installation from it's original install location, you will not have the option to install the OS runtime. This is due to your registry entries for Halo CE having incorrect paths.

If you have problems with OpenSauce not running follow these steps first.

1. Install Halo Custom Edition using the official installer.
2. Update Halo CE to version 1.09 by either initialising the update in-game, or running haloupdate.exe in the Halo CE root directory.
3. Install OpenSauce for Halo CE.

== Having problems? ==
If you are having problems when running the game, such as an exception, a black screen or other game breaking issue please search our issues page on the OS Google code website to see if it has already been reported and if not, create a new issue to inform us of the problem. This is the ONLY bug reporting system we are using. We will not look at issues sent to us via forum posts, private messages, e-mails, etc. This is so that we can track the issues appropriately.
	ALL Issues	http://code.google.com/p/open-sauce/issues/list?can=1 (includes issues that have been fixed/closed)
	Open Issues	http://code.google.com/p/open-sauce/issues/list

In the event of you having an exception, do NOT assume that you are having the same issue as somebody else unless you know what you are looking for in the exception details to determine whether it is an already reported issue. If in doubt, create a new issue and we will see if it is a duplicate and handle it accordingly.

When adding any issue to the database, add as much information as you can to help us debug the problem. For exceptions, please click the View Details button on the Send Report window that appears and copy the exception data into the issues description. That data will look something like this:

Problem Event Name: APPCRASH
Application Name: haloce.exe
Application Version: 1.0.9.620
Application Timestamp: 4ac7faf1
Fault Module Name: dinput8.dll
Fault Module Version: 3.0.0.0
Fault Module Timestamp: 4f16444a
Exception Code: c0000005
Exception Offset: 000126f6
OS Version: 6.1.7601.2.1.0.256.49
Locale ID: 1033

It is also useful for us to know your system specifications such as your graphics card, OS version, etc.

NOTE: The issues system is for problems and bugs ONLY. If you are unsure of how to use OS, please consult our wiki and/or create a post on Halomods to get community assistance. We are also NOT taking feature requests in any way.

== Change Log ==
=== Version 3.1.1 ===
  * ADD			added unit boarding
  * ADD			added entering biped unit seats
  * ADD			disableVehicleRemapper setting, along with a vehicle_remapper_enabled script function, to turn off the PC's vehicle respawning nonsense
  * FAIX [69]	object_data_get_real logic will no longer cause exceptions
  * FIX			fixed detail objects not being drawn when using os shader extensions

=== Version 3.1 ===
  * PATCH		project_yellow_globals tag features new flag for forcing the game to use 'stun jumping penalty' instead of 'turning penalty' in the engine's biped jump code
  * PATCH		non-multiplayer maps will no longer be selectable from the MP map list
  * CHANGE		Game hooking is now done via dinput8.dll instead of d3d9.dll
  * CHANGE		Removed XFire restriction now that we use dinput8.dll
  * CHANGE		Changed the server list to list all servers regardless of their version
  * CHANGE		Made OpensauceIDE an optional installation
  * CHANGE		Made XP SP3 a minimum requirement when installing
  * CHANGE		Installation now requires .NET 3.5
  * CHANGE		Increased hardcoded 'k_game_state_allocation_maximum_size_for_yelo' by 0x970 bytes
  * CHANGE		Increased hardcoded 'k_runtime_data_max_values_count' to a total of 64 (up from 32)
  * CHANGE		Made the GBuffer require SM 3.0
  * CHANGE		Clients now use "initc.txt" for their init.txt file
  * ADD			Added flag to use specular colour map alpha as a specular lighitng exponent mask
  * ADD			Make screenshots get saved to unique directorys to stop them from being overwritten
  * ADD			Upgraded the max number of particles active/rendered at once
  * ADD			Upgraded the max number of objects rendered at once
  * ADD			Ability for mainmenu maps to have animating objects
  * ADD			Added an xml setting for completely turning off game update checks
  * ADD			Added an in-game map download system to the client
  * ADD			Added a HTTP server to the OS dedi
  * ADD			Added a map server component to the OS dedi
  * ADD			Added an installation validation component to the installer
  * ADD			Added file patching component to the installer
  * ADD			Added new setting for forcing OS to use .yelo files first when searching for .map files (off by default)
  * ADD			Script functions for bit operations (AND, OR, etc) and converting hex string to an integer
  * ADD			Script function for playing a .bik movie just like how the engine plays credits.bik, etc (local games only)
  * ADD			New tag/script system for displaying ui widgets to the user
  * ADD			Added system for adding custom dedicated server logging events
  * ADD			Runtime vector3d values (part of the game state)
  * ADD			Added a mini crashdump creator for easier debugging
  * ADD			Added command line argument to disable all OS graphics (-no_os_gfx)
  * ADD			Added command line argument to disable special OS game state allocations (-no_os_gamestate)
  * ADD			Added Visual C++ 9.0 runtime to the installer
  * FIX			Fixed Halo not loading when using -use*
  * FIX			Fixed crash in shader model settings when extension element is missing
  * FIX [39]	Fixed GBuffer issues with stretched models and incorrect velocity when using custom models with high bone counts
  * FIX			Fixed shader models' specular lighting being dulled by detail maps when using detail before reflection
  * FIX			Fixed an exception on load when the device doesn't support hardware rendering (Intel integrated)
  * FIX			Fixed a bug where a non-existant map (of any kind) would cause the 'missing <mapname>.yelo' exception, when the stock game already had code to handle such cases
  * FIX			project_yellow tag's "prohibit_multiteam_vehicles" flag should work as expected now
  * FIX			Multi-team vehicles should no longer allow 'double loading'
  * FIX			Fix for instant respawns when using the OS dedi
  * FIX			Fixed the -path argument being ignored by OS
  * FIX			Fixed the roaming/appdata folders made by OS not being removed on uninstall
  * FIX [56]	Fixed the team index offset for MP teams for the GBuffer. MP teams now start at 10, not 9. This is a breaking fix, but I'm not aware of any major MP map releases that used this specific part of postprocessing

=== Version 3.0.3 ===
  * N/A			Nothing you all need to concern yourselves with. Go play Halo.

=== Version 3.0.2 ===
  * PATCH		Made a work-around for the HaloPC engine bug where model nodes over 43 were rendering wrong.
  * ADD			Verbose script definition mismatch messages when developer_mode is >= 4
  * FIX			Script definition mismatch error message erroneously prompting
  * FIX			Fixed tag-based gravity settings problem

=== Version 3.0.1 ===
  * REMOVED		Vehicle Views from F7 menu (it's unimplemented)
  * ADD			Implemented project_yellow's gravity_scale override field
  * ADD			Prompts user with a MessageBox when a map contains mismatching yelo script defintiions with the current build of OS
  * ADD			Bloom toggle added to the users settings
  * ADD			Shader extension toggle added to the user settings to completely disable it if needed
  * CHANGE		Motion blur is now disabled by default
  * FIX			Fixed potential issue when a proxy calling OS stores the device pointer in a local variable
  * FIX			Fixed possible issue where _global_yelo could reference invalid memory
  * FIX [19]	Unregistered mod-sets crash game w/o warning		http://code.google.com/p/open-sauce/issues/detail?id=19
  * FIX [17]	External PP effects problem w/ single model mask	http://code.google.com/p/open-sauce/issues/detail?id=17
  * FIX [14]	Weapon Views not saving correctly					http://code.google.com/p/open-sauce/issues/detail?id=14 (Thanks jellymasterer!)
  * FIX [13]	OS_haloceded crashes on startup						http://code.google.com/p/open-sauce/issues/detail?id=13
  * FIX [11]	Black screen when DisableAlphaRenderTargets is set	http://code.google.com/p/open-sauce/issues/detail?id=11 (Thanks as7raios!)
  * FIX [8]		HUD scaling causes problems with UI					http://code.google.com/p/open-sauce/issues/detail?id=8 (Thanks SeanAero!)
  * FIX [5]		HUD scaling has chatbox problem w/ hi-res			http://code.google.com/p/open-sauce/issues/detail?id=5 (Thanks SeanAero!)


== Known Issues ==
  * Running Steam with Halo in general sometimes causes the Function keys to not work. We can't fix this, it's on Valve's end. http://code.google.com/p/open-sauce/issues/detail?id=6&can=1
