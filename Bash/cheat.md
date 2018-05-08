Append "Hello" to file.txt
============================
 `$ echo "Hello" >> file.txt` 

Overwrite file.txt with "Hello"
=================================
 `$ echo "Hello" > file.txt`

Count the number of line of file.txt 
======================================
 `$ wc -l file.txt`

Sort the line of file.txt in out.txt  
======================================
 `$ sort file.txt > out.txt`

Execute a router on personal server 
=====================================
 `$ echo 1 > /proc/sys/net/ipv4/ip_forward`
 `$ iptables -A POSTROUTING -t nat -o enp0s3f3u7c2 -j SNAT --to 192.168.42.130`

