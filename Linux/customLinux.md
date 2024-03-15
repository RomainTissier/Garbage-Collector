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
* Debian (03/2024): minimal install (~150Mb of RAM) with JWM (~200Mb of RAM)
* OpenSuse (03/2024): heavy installer, minimal install (~250Mb of RAM)
* Fedora (03/2024): heavy installer, basic install do not include wifi config, minimal install (~400Mb of RAM)
* Archlinux (03/2024): archinstall cool installer, lxqt (~350Mb of RAM), cli (~160Mb)
* Void-Linux (03/2024): cli (~120Mb of RAM) with JWM (~200Mb of RAM)
* Alpine (03/2024): cli (~100Mb of RAM)
* NetBsd (03/2024): cli (~100Mb of RAM), JWM (~200Mb of RAM)
* Windows xp: 150Mb of RAM

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
* OpenSuse:
    * `zypper update`
    * `zypper patch`
    * `zypper patch-check`
    * `zypper dup`
* Netbsd:
  * `PKG_PATH="http://cdn.NetBSD.org/pub/pkgsrc/packages/NetBSD/$(uname -p)/$(uname -r|cut -f '1 2' -d.)/All/"`
  * `export PKG_PATH`
  * `pkg_add pkgin`
  * `pkgin update`
  * `pkgin full-upgrade`
  
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
* iwctl
  * Archlinux
    * `iwctl`
      * `device list`
      * `station wlan0 scan`
      * `station wlan0 get-networks`
      * `station wlan0 connect BoxRomain` 
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
* Alpine:
  * `setup-xorg-base`
  * `apk add xf86-input-libinput`
  * `addgroup romain input`
  * `addgroup romain video` 
  * `apk add font-terminus`

Configuration
* Dynamic keyboard configuration: `echo "setxkbmap be" > .xinitrc`
* Manual Keyboard configuration: 
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
* Alpine
  * `apk add lxqt-desktop`
  * `apk add lximage-qt`
  * `apk add obconf-qt`
  * `apk add pavucontrol-qt`
  * `apk add screengrab`
  * `apk add arandr` 
  * `apk add dbus`
  * `apk add dbus-x11`
  * ? `dbus-uuidgen > /var/lib/dbus/machine-id` ?
  * `rc-update add dbus`
  * echo "exec dbus-launch startlxqt" > .xinitrc

Common configuration:
* `echo "exec startlxqt" > ~/.xinitrc`

#### JWM
Install:
* Alpine
  * `apk add jwm`
  * `apk install setxkbmap`
* Debian
  * `apt install jwm`
* NetBsd: `pkgin install jwm` 

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
* Configure menu command (default command `onroot="12"` means left or right click)
  ```
  <RootMenu onroot="a">
      [...]
  </RootMenu>
    [...]
  <TrayButton icon="/home/romain/.local/share/jwm/start.png">root:a</TrayButton>
  ```
* Configure wallpaper image
  ```
  <Desktops width="4" height="1">
        <Background type="image">/home/romain/.local/share/jwm/wallpaper.png</Background>
  </Desktops>
  ```
* Configure window top bar with command icons:
  ```
  <ButtonClose>/home/romain/.local/share/jwm/btn_close.png</ButtonClose>
  <ButtonMax>/home/romain/.local/share/jwm/btn_max.png</ButtonMax>
  <ButtonMaxActive>/home/romain/.local/share/jwm/btn_max_active.png</ButtonMaxActive>
  <ButtonMin>/home/romain/.local/share/jwm/btn_min.png</ButtonMin>
  ```
* Remove "motif" 3D effect by replacing `decorations="motif"` by `decoration="flat"`
* Remove opacity everywhere: `<Opacity>1.0</Opacity>`
* Set window frame style:
  * Rounded: `<WindowStyle>[..]<Corner>5</Corner>[..]</WindowStyle>`
  * Square: `<WindowStyle>[..]<Corner>0</Corner>[..]</WindowStyle>`

#### Terminal
* `apt install stterm`

#### File manager
* `apt install pcmanfm`

#### Usb automount
* VoidLinux: Activate USB automount by enabling service `ln -s /etc/sv/dbus /var/service/dbus`
* Alpine:
  * `setup-devd udev`
  * `apk add gvfs`
  * `apk add udisks2`
  * `apk add elogind`
  * `apk add polkit-elogind`
  * `rc-update add elogind`
  * `addgroup -S yourusername users`
  * `addgroup -S yourusername disk`  
 
#### Webbrowser
* `apt install firefox-esr`

#### Clipboard
* Debian: N/A

#### Sound
* Debian
  * `apt install pulseaudio`
  * `apt install pamixer`
  * `apt install pavucontroll`
* Alpine
  * `apk add pulseaudio` 

#### Multi-screen
* Debian: `apt install arandr`
