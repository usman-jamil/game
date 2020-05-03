# Welcome to Game!

- Download SFML Source Code: https://www.sfml-dev.org/download/sfml/2.5.1/ extract source code to: C:\SFML-2.5.1
- Open Visual Studio Command Prompt and execute
-- cmake -S "C:\SFML-2.5.1" -B "C:\SFML-2.5.1" -DBUILD_SHARED_LIBS=OFF -DBUILD_STATIC_LIBS=ON
- Open Project in Visual Studio and open project properties. Change the seetings for both DEBUG and RELEASE configurations against x64 as shown below
# DEBUG

- Additional include directories: C:\SFML-2.5.1\include;
- Preprocessor: SFML_STATIC;
- Additional library directories: C:\SFML-2.5.1\lib\Debug;C:\SFML-2.5.1\extlibs\libs-msvc\x64;
- Additional dependencies: opengl32.lib;openal32.lib;freetype.lib;winmm.lib;gdi32.lib;flac.lib;vorbisenc.lib;vorbisfile.lib;vorbis.lib;ogg.lib;ws2_32.lib;sfml-graphics-s-d.lib;sfml-window-s-d.lib;sfml-system-s-d.lib;sfml-audio-s-d.lib;sfml-network-s-d.lib;

# RELEASE
- Additional include directories: C:\SFML-2.5.1\include;
- Preprocessor: SFML_STATIC;
- Additional library directories: C:\SFML-2.5.1\lib\Release;C:\SFML-2.5.1\extlibs\libs-msvc\x64;
- Additional dependencies: opengl32.lib;openal32.lib;freetype.lib;winmm.lib;gdi32.lib;flac.lib;vorbisenc.lib;vorbisfile.lib;vorbis.lib;ogg.lib;ws2_32.lib;sfml-graphics-s.lib;sfml-window-s.lib;sfml-system-s.lib;sfml-audio-s.lib;sfml-network-s.lib;
