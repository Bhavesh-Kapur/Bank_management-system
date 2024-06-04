## GUI compilation 
### MacOS
GTK3 - v3
<ul>
<li>  

```bash
brew install gtk3
```

</li>

pkg-config - package 

<li>

```bash
brew install pkg-config
```

</li>


CMD for compilation 

<li>

```bash
gcc -o window window.c `pkg-config --cflags --libs gtk+-3.0`
```

</li>

you can change the window and window.c depending upon your program
</ul>

## Windows

<ul>
<li> Install <a href="https://www.msys2.org/">MSYS2</a> Then Open MSYS2-MinGW Terminal </li>
<li>Update packages using  </li>


```bash
pacman -Syu
```

<li> Install GTK 3.0 and pkg-config files</li>

```bash 
pacman -S mingw-w64-x86_64-gtk3 mingw-w64-x86_64-pkg-config
```
<li>Set the Environment Variables</li>

```bash 
set PATH=C:\msys64\mingw64\bin;C:\msys64\usr\bin;%PATH%
```
<li> Navigate to your project Directory </li>

<li>Configure your pkg-config files for CFLAGS AND LIBS</li>

```bash 
for /f "tokens=* USEBACKQ" %F in (`pkg-config --cflags gtk+-3.0`) do set CFLAGS=%F
for /f "tokens=* USEBACKQ" %F in (`pkg-config --libs gtk+-3.0`) do set LIBS=%F
```

<li>Compiling </li>

```bash
gcc -o file_name file_name.c %CFLAGS% %LIBS%
```
