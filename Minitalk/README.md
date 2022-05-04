# Minitalk :loud_sound::fax:	

## Description
Communication program in the form of **client** and **server**.

The client sends the string passed as parametr to server using UNIX signals SIGUSR1 and SIGUSR2.

The server receives signlas, collects each 8 bits in 1 character and then creates and prints string.

In case of errors (wrong PID/signal was not delivered/etc) you will see error message in your terminal.  

Unicode characters are supported, thus you can send emoji from the client to the server. :upside_down_face:
### Bonus part
In bonus part the server acknowledges every message received by sending back a signal to the server. 
At the end of each string the server and the client display messages that string was delivered.

## Usage
* Download this repo;
* Create executable files **`server and client`** using command **make** or **`server_bonus and client_bonus`** using command **make bonus**;
* Run programm **server** or **server_bonus**, copy PID of server that you will see in your terminal window;
* Run programm **client** or **client_bonus** (**`./[name of program] [server's PID] [String to send]`**).
