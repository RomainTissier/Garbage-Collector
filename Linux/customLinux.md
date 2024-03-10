Custom install of Linux
=========================

  Configure network
  -------------------
    * Alpine : 
      ° During the installation : setup-interfaces 
      ° Restart network service : /etc/init.d/networking restart
      ° Increase retry (10 times) to connect wifi : 
        - In /etc/network/interfaces add : udhcpc_opts -t 10
        
  Manage repos 
  --------------
    * /etc/apk/repositories
    * /etc/apt/sources.list
        
  Ajout utilisateur
  -------------------
    * adduser romain
        
  Configure ls
  --------------
    * echo 'alias ll="ls -al"' >> .bashrc

  Install vim 
  -------------
    * `apt install vim` ou `apk add vim`
    * echo 'alias vi="vim"' >> .bashrc

  Webbrowser
  ------------
    * links2 : minimal browser no javascript
    * luakit : simple browser (interface like vim), handle simple javascript
    * qutebrowser: simple browser (in python), handle simple javascript
    * netsurf : very fast browser, no javascript

  Install Jwm alpine
  --------------------
    * setup-xorg-base
    * apk add jwm
    * echo "exex jwm" > .xinitrc
    * cp /etc/system.jwmrc .jwmrc
    * apk install setxkbmap

  Install Jwm
  -------------
    * `apt install jwm`
    * `apt install xinit`
    * `apt install stterm`
    * `cp /etc/jwm/system.jwmrc .jwmrc`
  
  Try X and Jwm
  ----------------
    * `startx`
    * Open terminal in order to execute setxkbmap fr
  
  Start wifi (nixos)
  --------------------
    * `sudo systemctl start wpa_supplicant`
    * `wpa_cli`
    * `scan`
    * `add_network`
        `-> 0`
    * `set_network 0 ssid "MyWifi"`
    * `set_network 0 psk "MyPassword"`

  Configure keyboard (nixos)
  ----------------------------
    * `loadkeys fr`
    * `enable_network 0`
        -> CTRL-EVENT-CONNECTED

  Configure partitions (from nixos installation guide)
  ------------------------------------------------------
    * parted /dev/sda -- mklabel msdos
    * parted /dev/sda -- mkpart primary 1MB -8GB
    * parted /dev/sda -- set 1 boot on
    * parted /dev/sda -- mkpart primary linux-swap -8GB 100%
    * mkfs.ext4 -L nixos /dev/sda1
    * mkswap -L swap /dev/sda2
    * mount /dev/disk/by-label/nixos /mnt
    * swapon /dev/sda2
  
  Reminders / Notes on distro
  -----------------------------
    * NixOs: command line installation, simple wiki instruction, the configuration is handled by a text file: configuration.nix, package management too slow on very old computers
    * Crux: the manual compilation of linux kernel is slow with very old hardware.

Notes on void installation
----------------------------
* Activate USB automount by enabling service: `ln -s /etc/sv/dbus /var/service/dbus`



Lightweight env
-----------------

### Basic distribution install
* Install minimal version of any distribution, without X server

### Command line editor
* Installation:
  * `apt install vim`
* Configuration:
  * .bashrc: `alias vi='vim'`
  * .vimrc: `syntax on`  

### Shell configuration
* .bashrc or .shrc
  * `alias ls='ls -G'`
  * Congigure PS1:
    ```
    PS1="whoami@hostname | sed 's/\..*//'"
    case id -u in
        0) PS1="${PS1}# ";;
 	      *) PS1="${PS1}$ ";;
    esac
    ```

### Update to latest version
* Debian
  * Edit `/etc/apt/source.list` and replace version code by `testing`
  * `apt update`
  * `apt upgrade`
  * `apt update`
  * `apt dist-upgrade`
  * `reboot`
* FreeBsd
  * Update system 
    * `freebsd-update fetch`
    * `freebsd-update install`
  * Upgrade system
    * `freebsd-update -r 11.0-RELEASE upgrade`
    * `freebsd-update install`
    * `reboot`
    * `freebsd-update install`
  * Update packages
    * `pkg update`
    * `pkg upgrade`

### Network
* NetworkManager (provide nmtui)
  * Debian
    * `apt install network-manager`
    * Mannually edit `/etc/network/interface` to remove original config
    * `reboot`
    * `nmtui`
    * `reboot`

### X server
Install
* Debian `apt install xorg`
* Archlinux (example with intel driver)
  * `pacman -Syu xorg-server xf86-video-intel`
  * `pacman -Syu xorg-x11-xinit (provide startx)`
* VoidLinux (the order of package installation is very important)
  * 1: `xbps-install -Su void-repo-nonfree`
  * 2: `xbps-install -Su linux-firmware-intel`
  * 3: `xbps-install -Su mesa-dri`
  * 4: `xbps-install -Su vulkan-loader`
  * 5: `xbps-install -Su mesa-vulkan-intel`
  * 6a: `xbps-install -Su libva-intel-driver` (warning: only for CPU before broadwell excluded)
  * 6b: `xbps-install -Su intel-media-driver` (after broadwell)
  * 7: `xbps-install -Su xorg`

Configuration
*  Keyboard   clavier FR : 
  * Freebsd `/etc/X11/xorg.conf.d/10-keyboard0`:
    ```
    Section "InputClass"
    	Identifier "Keyboard0"
    	Driver "kbd"
    	MatchIsKeyboard "on"
    	Option "XkbModel" "pc105"
    	Option "XkbRules" "xorg"
    	Option "XkbLayout" "fr"
    	Option "XkbVariant" "oss"
    ```


### Desktop environment
#### LxQt
Installation:
* Debian (too heavy):
  * `apt install lxqt-core`
* VoidLinux
  * `xbps-install -Su lxqt`

Common configuration:
* `echo "exec startlxqt" > ~/.xinitrc`


### TODO
#### Usb automount
#### Disk management
#### Webbrowser
#### Clipboard
#### Sound
#### Multi screen
