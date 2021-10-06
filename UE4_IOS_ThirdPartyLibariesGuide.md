# Unreal Engine Third Party Libaries, Includes, and frameworks. Mainly for IOS / OSX
### Daniel Orchard 06-Oct-2021. Notes to self.

<hr>

## Wrap Platform Rules
```c#
if (Target.Platform == UnrealTargetPlatform.IOS)
{
    System.Console.WriteLine("... LibrariesPath -> " + LibrariesPath);
}

if (Target.Platform.IsInGroup(UnrealPlatformGroup.Windows))
{

}

```

## Public Libaries
If a system is included on the device by default at an OS level, as a dylib or dll, you skip the lib wording, and dylib suffix, and add it to the Public System Libraries. IE:

```c#
PublicSystemLibraries.Add("z");
PublicSystemLibraries.Add("iconv");
PublicSystemLibraries.Add("bz2");
```

## Frameworks
[Apple Framework List](https://developer.apple.com/library/archive/documentation/MacOSX/Conceptual/OSX_Technology_Overview/SystemFrameworks/SystemFrameworks.html)

If you need to include one of the Frameworks, such as those provided by Apple in a framework format, do the below:
```c#
PublicFrameworks.AddRange(
    new string[] {
                    "CoreMedia",
                    "CoreVideo",
                    "AVFoundation",
                    "AudioToolbox",
                    "VideoToolbox",
                    "QuartzCore",
    }); 

```


## Local Static Libaries
If you need to package a static library, .lib for windows, .a for OSX / IOS. You seem to need to use the engine directory and not a plugin, due to a staging bug I have not solved. So you code goes like this:

```c#
string EngineThirdPartyPath = Target.UEThirdPartySourceDirectory;
string IncPath = Path.Combine(EngineThirdPartyPath, "FOLDER/ffmpeg/include");
string LibPath = Path.Combine(EngineThirdPartyPath, "FOLDER/ffmpeg/lib");

string[] libs = { "libavcodec.a", "libavdevice.a", "libavfilter.a", "libavformat.a", "libavutil.a", "libswresample.a", "libswscale.a" };

foreach (string lib in libs)
{
    PublicAdditionalLibraries.Add(Path.Combine(LibPath, "IOS", lib));
}
```

## Public Includes
Add path to the headers included with a library
```c#
string EngineThirdPartyPath = Target.UEThirdPartySourceDirectory;
string IncPath = Path.Combine(EngineThirdPartyPath, "FOLDER/ffmpeg/include");

PublicIncludePaths.Add(IncPath);
```


## UPL's
Mostly for Android, but can be used on IOS. Example:
```c#
 AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(PluginPath, "ElectraPlayerRuntime_UPL.xml"));
```