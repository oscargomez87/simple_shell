#  Simple Shell

<p align="center">
<img src="https://miro.medium.com/max/740/1*lV2jcZgF3gczl2w_8TFXOg.png" />
</p>

Simple Shell is a program created to run in a Linux-like operating system, to capture and execute commands from the user. It's designed to mimic sh shell.

## Requirements

### General

-   Compiled using Ubuntu 20.04 with gcc 4.8.4

### Compilation

**Simple Shell** was compiled this way:

```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
### Testing

Simple Shell works like this in interactive mode:

```
>./hsh
$ /bin/ls
hsh main.c shell.c
$
$ exit
>
```

But also in non-interactive mode:

```
> echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
>
> cat test_ls_2
/bin/ls
/bin/ls
>
> cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
>
```
## Flowchart

![Image of Flowchart](https://i.imgur.com/GUtPTTZ.jpg)
## Getting Started

Use the following command to execute Simple Shell:

    ./hsh
After this, the Simple Shell will be executed and a prompt will appears as follow:

    $_
To exit from Simple Shell just put the following command and press enter key:

    $exit

## Supported Builtin Functions and Variables

| Builtin | Description |
|:-------:| ----------- |
| env | Display the environmental variables |
| exit | Exit the Shimple Shell |
| $?| Enviromental variable to store error exit code for each command|


### Examples

```
$ ls -al
total 104
drwxrwxr-x  3 vagrant vagrant  4096 Nov 26 21:48 .
drwxrwxr-x 11 vagrant vagrant  4096 Nov 23 20:10 ..
drwxrwxr-x  8 vagrant vagrant  4096 Nov 26 21:48 .git
-rw-rw-r--  1 vagrant vagrant    77 Nov 23 15:52 .gitignore
-rw-rw-r--  1 vagrant vagrant   202 Nov 26 21:48 AUTHORS
-rw-rw-r--  1 vagrant vagrant  2123 Nov 17 18:06 README.md
-rw-rw-r--  1 vagrant vagrant   209 Nov 26 21:48 _builtin.c
-rw-rw-r--  1 vagrant vagrant   829 Nov 26 21:48 _exec.c
-rw-rw-r--  1 vagrant vagrant   910 Nov 26 21:48 _findcmd.c
-rw-rw-r--  1 vagrant vagrant   377 Nov 26 21:48 _free_all.c
-rw-rw-r--  1 vagrant vagrant   513 Nov 23 15:52 _getenv.c
-rw-rw-r--  1 vagrant vagrant   842 Nov 26 21:48 _getpath.c
-rw-rw-r--  1 vagrant vagrant  1133 Nov 26 21:48 _itty.c
-rw-rw-r--  1 vagrant vagrant  1201 Nov 26 21:48 _ntty.c
-rw-rw-r--  1 vagrant vagrant   716 Nov 26 21:48 _read.c
-rw-rw-r--  1 vagrant vagrant  1341 Nov 26 21:48 _tokens.c
-rwxrwxr-x  1 vagrant vagrant   381 Nov 23 15:52 generate-authors.sh
-rwxrwxr-x  1 vagrant vagrant 14529 Nov 26 21:48 hsh
-rw-rw-r--  1 vagrant vagrant   448 Nov 26 21:48 main.c
-rw-rw-r--  1 vagrant vagrant  2011 Nov 23 15:52 man_1_simple_shell
-rw-rw-r--  1 vagrant vagrant   587 Nov 26 21:48 shs.h
-rw-rw-r--  1 vagrant vagrant    17 Nov 23 17:48 test
-rw-rw-r--  1 vagrant vagrant    16 Nov 23 17:48 test~
$
$ env
XDG_SESSION_ID=2
TERM=xterm-256color
SHELL=/bin/bash
SSH_CLIENT=10.0.2.2 56335 22
SSH_TTY=/dev/pts/0
USER=vagrant
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arj=01;31:*.taz=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.zip=01;31:*.z=01;31:*.Z=01;31:*.dz=01;31:*.gz=01;31:*.lz=01;31:*.xz=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.jpg=01;35:*.jpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.axv=01;35:*.anx=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.axa=00;36:*.oga=00;36:*.spx=00;36:*.xspf=00;36:
MAIL=/var/mail/vagrant
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games
PWD=/home/vagrant/projects/simple_shell
LANG=en_US.UTF-8
SHLVL=1
HOME=/home/vagrant
LOGNAME=vagrant
SSH_CONNECTION=10.0.2.2 56335 10.0.2.15 22
LESSOPEN=| /usr/bin/lesspipe %s
XDG_RUNTIME_DIR=/run/user/1000
LESSCLOSE=/usr/bin/lesspipe %s %s
_=./hsh
OLDPWD=/home/vagrant/projects
$
$ asdf
./hsh: 1: asdf: not found
$ echo $?
127
$ /vmlinuz
./hsh: 2: /vmlinuz: Permission denied
$
$ echo $?
126
$ pwd
/home/vagrant/projects/simple_shell
$
$ echo ok
ok
$ exit
>
```

## Authors

* **Oscar Gomez Toro** - *Initial work* - [oscargomez87](https://github.com/oscargomez87)
* **Leonardo Calderon Jaramillo** - *Initial work* - [leocjj](https://github.com/leocjj)
