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
The order of package installation is very important:
* 1: `xbps-install -Su void-repo-nonfree`
* 2: `xbps-install -Su linux-firmware-intel`
* 3: `xbps-install -Su mesa-dri`
* 4: `xbps-install -Su vulkan-loader`
* 5: `xbps-install -Su mesa-vulkan-intel`
* 6a: `xbps-install -Su libva-intel-driver` (warning: only for CPU before broadwell excluded)
* 6b: `xbps-install -Su intel-media-driver` (after broadwell)
* 7: `xbps-install -Su xorg`
* 8: `xbps-install -Su lxqt`
* Activate USB automount by enabling service: `ln -s /etc/sv/dbus /var/service/dbus`

Xorg/11
---------
* pacman -Syu xorg-server xf86-video-intel
* pacman -Syu xorg-x11-xinit (provide startx)
