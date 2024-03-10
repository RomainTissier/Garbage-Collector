Custom install of Linux
=========================

Webbrowser
------------
* links2 : minimal browser no javascript
* luakit : simple browser (interface like vim), handle simple javascript
* qutebrowser: simple browser (in python), handle simple javascript
* netsurf : very fast browser, no javascript

Reminders / Notes on distro
-----------------------------
* NixOs: command line installation, simple wiki instruction, the configuration is handled by a text file: configuration.nix, package management too slow on very old computers
* Crux: the manual compilation of linux kernel is slow with very old hardware.

Lightweight env
-----------------

### Basic distribution install
Install minimal version of any distribution, without X server

#### Configure keyboard
Archlinux/Voidlinux/Nixos: `loadkeys fr`

#### Configure partition (from nixos installation guide)
* `parted /dev/sda -- mklabel msdos`
* `parted /dev/sda -- mkpart primary 1MB -8GB`
* `parted /dev/sda -- set 1 boot on`
* `parted /dev/sda -- mkpart primary linux-swap -8GB 100%`
* `mkfs.ext4 -L nixos /dev/sda1`
* `mkswap -L swap /dev/sda2`
* `mount /dev/disk/by-label/nixos /mnt`
* `swapon /dev/sda2`

### Command line editor
* Installation:
  * `apt install vim` (Debian)
  * `apk add vim` (Alpine)
* Configuration:
  * .bashrc: `alias vi='vim'`
  * .vimrc: `syntax on`  

### Manage user
* `useradd romain`

### Shell configuration
* .bashrc or .shrc
  * `alias ls='ls -G'`
  * `alias ll="ls -al"`
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
* Alpine: source are configured in `/etc/apk/repositories`

### Network
* NetworkManager (provide nmtui)
  * Debian
    * `apt install network-manager`
    * Mannually edit `/etc/network/interface` to remove original config
    * `reboot`
    * `nmtui`
    * `reboot`
* wpa_supplicant (Wifi)
  * Nixos
    * `sudo systemctl start wpa_supplicant`
    * `wpa_cli`
    * `scan`
    * `add_network`
        `-> 0`
    * `set_network 0 ssid "MyWifi"`
    * `set_network 0 psk "MyPassword"`

* Other manager
  * Alpine
    * During the installation : `setup-interfaces`
    * Restart network service : `/etc/init.d/networking restart`
    * Increase retry (10 times) to connect wifi : 
      * - In `/etc/network/interfaces` add : `udhcpc_opts -t 10`

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
* Alpine: `setup-xorg-base`

Configuration
* Manual keyboard conf: `setxkbmap be`
* Auto Keyboard: 
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

#### JWM
Install:
* Alpine
  * `apk add jwm`
  * `apk install setxkbmap`
* Debian
  * `apt install jwm`

Configuration:
* `echo "exex jwm" > .xinitrc`
* Copy .jwmrc
  * `cp /etc/system.jwmrc .jwmrc` (Alpine)
  * `cp /etc/jwm/system.jwmrc .jwmrc` (debian)
* Snap window (this behavior allow to resize window to the half of screen when user move it to screen edge) configuration in `.jwmrc`
  ```
  <Group>
      <!-- <Option>tiled</Option> -->
      <Option>aerosnap</Option>
  </Group>
  ```

#### Terminal
* `apt install stterm`

#### Usb automount
* VoidLinux: Activate USB automount by enabling service `ln -s /etc/sv/dbus /var/service/dbus`

### TODO
#### Smart window split
#### Disk management
#### Webbrowser
#### Clipboard
#### Sound
#### Multi screen
