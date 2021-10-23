clc
delete(instrfindall)
s1 = serialport('COM6', 9600);
data = zeros(100,1000);
go = true;
while(go)
    for i = 1:100
        for j = 1:1000
            data(i,j) = read(s1,1,"double");
            plot(data(i,j),"red");
            drawnow;
        end
    end
    go = false;
    writematrix('emgdata.csv', data);
    delete(instrfindall)
end