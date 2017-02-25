Copyright:   cairui</br>
Author:      cairui</br>
Date:        2017-02-26</br>
Description: using tcp connect to test net.can bind interface or ip, can set timeout.</br>

### usage:
>./cr_net_test</br>
>		-h : print help;</br>
>		-s : connect server domain;</br>
>		-p : connect server port;</br>
>		-i : bind interface, eg: eth1 or 192.168.1.1; can be empty;</br>
>		-t : timeout second, default 3s;</br>
		
### example:
```
./cr_net_test -s www.google.com -p 80 -i eth0 -t 5
./cr_net_test -s www.facebook.com -p 443 -i 192.168.1.233:23345
./cr_net_test -s www.baidu.com -p 80 -t 3
```
