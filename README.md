# 📡 minitalk
Server and client that communicate using 2 signals (SIGUSR1 and SIGUSR2). The client sends each bit value using bitwise and the server translates it back to a char.

![minitalk](https://user-images.githubusercontent.com/74905890/129451065-d1f77eb8-6a26-43c5-8ee2-e10f374552b7.gif)

## Features
- Sends 1000 chars in less than 2 seconds.
- Supports unicode.

## How to use
1. Run make at the root folder
2. Run `./server` and copy the PID that it displays
3. Run `./client PID "Message"`

 
