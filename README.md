# minitalk

## 1. What is Minitalk?
Minitalk is designed to create a lightweight messaging system where a server prints its process ID (PID) and waits for incoming messages, and a client sends a string message to the server. The communication occurs solely through UNIX signals, making it a minimal yet effective demonstration of IPC (Inter-Process Communication).
It demonstrates inter-process communication by transmitting messages between processes using only two signals: SIGUSR1 and SIGUSR2.
- *The server* receives messages from the client and prints them to the screen.
- *The client* sends messages to the server through signals.

## 2. Usage
### *Starting the Server*

  To run the server:

  ```./server```
  
  This command will display the Process ID (PID) of the server.
### *Sending Messages from the Client*

To send a message from the client to the server:

```./client <SERVER_PID> "Message to send"```


## 3. What is PID?
PID stands for Process Identifier. It is a unique number assigned by the operating system to each running process. In the context of Minitalk, the server displays its PID so that clients know the destination process to which they should send their messages.

## 4. What are the kill and signal functions?
```kill()``` Function:

This function is used to send a signal to a process identified by its PID. In Minitalk, kill() transmits the message bits by sending either SIGUSR1 or SIGUSR2 to the server.

```signal()``` Function:

This function sets up a custom signal handler. When a specific signal (such as SIGUSR1 or SIGUSR2) is received, the defined handler executes to process the incoming data. This is crucial for Minitalk to properly receive and interpret the bits of the transmitted message.


## 5. Bit Manipulation (Examples)
### Setting a bit     
To set a specific bit of an integer to 1, we use the bitwise OR (|) operation.

```current_char |= (1 << bit);```

    

 ### Retrieving the Value of a Specific Bit in an Integer
To check whether a specific bit in an integer is 0 or 1, we use the bitwise AND (&) operation.

```c
if (c & (1 << bit))
  kill(pid, SIGUSR1);
else
  kill(pid, SIGUSR2);
```

we have the number 9 (binary: 00001001) and we want to check the **3rd** bit.
- *Create a mask: 1 << 3*
  
  1 (binary: 00000001) is shifted left by 3 bits → 00001000 (8)

- *bitwise AND operation:*
```txt
    00001001  (9)
AND 00001000  (bit mask: 1 << 3)
----------------
    00001000  (8)  → The result is nonzero, meaning the bit is 1.
```
    
