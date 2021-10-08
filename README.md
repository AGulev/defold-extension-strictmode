# Defold Native Extension StrictMode

Native Extension for Defold Game Engine that gives a possibility to use [StrictMode](https://developer.android.com/reference/android/os/StrictMode.html) on Android

## Installation
Copy-paste `strict_mode` section from extensions [game.project](https://github.com/AGulev/defold-extension-strictmode/blob/3faab456a92d7c861fd4dcfab0712cb63e8a0170/game.project#L17) into your `game.project`

Possible `fdsan_level` values are:
```
0 -- ANDROID_FDSAN_ERROR_LEVEL_DISABLED
1 -- ANDROID_FDSAN_ERROR_LEVEL_WARN_ONCE
2 -- ANDROID_FDSAN_ERROR_LEVEL_WARN_ALWAYS
3 -- ANDROID_FDSAN_ERROR_LEVEL_FATAL

```
All the other fields are boolean values and maybe 1 or 0 ON/OFF.

## Issues and suggestions

If you have any issues, questions or suggestions please [create an issue](https://github.com/AGulev/defold-extension-strictmode/issues) or contact me: me@agulev.com
