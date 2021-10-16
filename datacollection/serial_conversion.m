clc
delete(instrfindall)
s = serialport('COM6', 9600);
fopen(s);
set(s, 'terminator', char(37))
emgdata = zeros(100,1000);
for i = 1:100
    for j = 1:1000
        emgdata(i,j) = fscanf(s);
    end
end
xlswrite('emgdata.xls', emgdata);
fclose(s);
delete(instrfindall)
