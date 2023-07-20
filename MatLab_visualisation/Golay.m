N = 1000;
R = 83;
l = 240;
l_space = 40;
l_coil = 100;
start1 = -l / 2;
end1 = start1 + l_coil;
start2 = end1 + l_space;
end2 = start2 + l_coil;

theta=pi()/6;
phi=zeros(1,N);
phi(1:N/8)=linspace(theta,pi()-theta,N/8);
phi(N/8+1:N/4)=pi()-theta;
phi(N/4+1:3*N/8)=linspace(pi()-theta,theta,N/8);
phi(3*N/8+1:N/2)=theta;
phi(N/2+1:5*N/8)=linspace(pi()+theta,2*pi()-theta,N/8);
phi(5*N/8+1:3*N/4)=2*pi()-theta;
phi(3*N/4+1:7*N/8)=linspace(11*pi()/6,7*pi()/6,N/8);
phi(7*N/8+1:length(phi))=pi()+theta;
x=R*cos(phi);
z=R*sin(phi);
y(1:N/8)=start1;
y(N/8+1:N/4)=linspace(start1,end1,N/8);
y(N/4+1:3*N/8)=end1;
y(3*N/8+1:N/2)=linspace(end1,start1,N/8);
y(N/2+1:5*N/8)=start1;
y(5*N/8+1:3*N/4)=linspace(start1,end1,N/8);
y(3*N/4+1:7*N/8)=end1;
y(7*N/8+1:N)=linspace(end1,start1,N/8);


theta=pi()/6;
phi2=zeros(1,N);
phi2(1:N/8)=linspace(theta,pi()-theta,N/8);
phi2(N/8+1:N/4)=pi()-theta;
phi2(N/4+1:3*N/8)=linspace(pi()-theta,theta,N/8);
phi2(3*N/8+1:N/2)=theta;
phi2(N/2+1:5*N/8)=linspace(pi()+theta,2*pi()-theta,N/8);
phi2(5*N/8+1:3*N/4)=2*pi()-theta;
phi2(3*N/4+1:7*N/8)=linspace(11*pi()/6,7*pi()/6,N/8);
phi2(7*N/8+1:length(phi2))=pi()+theta;
x2=R*cos(phi2);
z2=R*sin(phi2);
y2(1:N/8)=start2;
y2(N/8+1:N/4)=linspace(start2,end2,N/8);
y2(N/4+1:3*N/8)=end2;
y2(3*N/8+1:N/2)=linspace(end2,start2,N/8);
y2(N/2+1:5*N/8)=start2;
y2(5*N/8+1:3*N/4)=linspace(start2,end2,N/8);
y2(3*N/4+1:7*N/8)=end2;
y2(7*N/8+1:N)=linspace(end2,start2,N/8);

hold on
plot3(x, y, z)
hold on
plot3(x2, y2, z2)
hold on

%{
fid1 = fopen('coil1.txt', 'w');
fid2 = fopen('coil2.txt', 'w');
fid3 = fopen('coil3.txt', 'w');
fid4 = fopen('coil4.txt', 'w');

for i = 1:500
   fprintf(fid1, '%f %f %f\n', x(i), y(i), z(i));
   fprintf(fid2, '%f %f %f\n', x(i + 500), y(i + 500), z(i + 500));
   fprintf(fid3, '%f %f %f\n', x2(i), y2(i), z2(i));
   fprintf(fid4, '%f %f %f\n', x2(i + 500), y2(i + 500), z2(i + 500));
end
fclose(fid1);
fclose(fid2);
fclose(fid3);
fclose(fid4);
%}

fileID = fopen("small_field.txt");
C = textscan(fileID,'%f\t%f\t%f\t%f\t%f\t%f');
fclose(fileID);

axis equal

%layer
new_x = [];
new_y = [];
new_z = [];
new_U = [];
new_V = [];
new_W = [];
for i = 1:1:length(C{1, 3})
    if(C{1, 3}(i) == 0)
        new_x = [new_x C{1, 1}(i)];
        new_y = [new_y C{1, 2}(i)];
        new_z = [new_z C{1, 3}(i)];
        new_U = [new_U C{1, 4}(i)];
        new_V = [new_V C{1, 5}(i)];
        new_W = [new_W C{1, 6}(i)];
    end
end

quiver3(new_x, new_y, new_z, new_U, new_V, new_W);
figure()

plot3(x(1:500), y(1:500), z(1:500))
hold on
plot3(x(501:1000), y(501:1000), z(501:1000))
hold on
plot3(x2(1:500), y2(1:500), z2(1:500))
hold on
plot3(x2(501:1000), y2(501:1000), z2(501:1000))
hold on
quiver3(C{1, 1}, C{1, 2}, C{1, 3}, C{1, 4}, C{1, 5}, C{1, 6})
axis equal