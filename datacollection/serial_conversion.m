clc
delete(instrfindall)
s = serialport('COM6');
fopen(s);
set(s, 'BaudRate', 9600)
set(s, 'terminator', char(37))
for i = 1:1000
    temp = fscanf(s);
    