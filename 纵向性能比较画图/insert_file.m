%[1]
x1=[1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
y1=[700,1025,1344,1658,1970,2286,2603,2918,3228,3538];

plot(x1, y1, '-o', 'LineWidth', 1, ...
                'MarkerEdgeColor', 'k', ...
                'MarkerFaceColor', 'r', ...
                'MarkerSize', 5);

title('�ļ��������');
xlabel('��¼����ʮ��');
ylabel('��ʱ���룩');
axis([0, 11, 100, 4200]);
hold on;

%[2]
x2=[1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
y2=[322,650,1002,1340,1683,2036,2431,2757,3174,3586];

plot(x2, y2, '-o', 'LineWidth', 1, ...
                'MarkerEdgeColor', 'k', ...
                'MarkerFaceColor', 'g', ...
                'MarkerSize', 5);
hold on;

%[3]
x2=[1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
y2=[472,890,1407,1887,2360,2685,3009,3330,3652,3973];

plot(x2, y2, '-o', 'LineWidth', 1, ...
                'MarkerEdgeColor', 'k', ...
                'MarkerFaceColor', 'y', ...
                'MarkerSize', 5);
hold on;
