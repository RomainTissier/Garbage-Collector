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

  Install Jwm alpine
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

