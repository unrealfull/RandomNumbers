clc;
clear;
close all;
ran = ["ran0" "ran1" "ran2" "ran3" "ran4"];
samplesize = [5 10 100 10000];

% make sure test files and this file are in the same directory
% or put this file in ./files

for i = 1 : length(ran)
    fprintf("\nTest for %s:\n",ran(i))
    for j = 1 : length(samplesize)
        filename = ran(i) + "_" + samplesize(j) + ".csv";
        fprintf("\n Samplesize %d:",samplesize(j))
        numbers = readtable(filename);
        numbers = table2array(numbers);

        if samplesize(j) <= 10
           bt = fitdist(numbers, 'Binomial','NTrials', samplesize(j));
           if bt.p < 0.05
            fprintf("\n  p is %d\n",bt.p)
            fprintf("  p < 0.05 => reject the hypothesis\n");
           else
            fprintf("\n  p is %d\n",bt.p)
            fprintf("  p > 0.05 => no reason to reject the hypothesis\n");
           end
        end
        if samplesize(j) > 10
            
            numbers = sortrows(numbers);

            
            numbers = (numbers-mean(numbers))/std(numbers);
            
            cdfplot(numbers)
            hold on
            plot(numbers, normcdf(numbers), "r--")
            legend("observed CDF", "ECDF")
            
            [h, p, k, c] = kstest(numbers, [],.05,0);
            
            if h == 1
                h0 = "reject the hypothesis";
            else
                h0 = "no reason to reject the hypothesis";
            end
            
            fprintf("\n  h = %d => %s \n  The returned p value is %d \n  The returned k value is %d \n  The critical value is %d \n",h,h0,p,k,c)
        end
    end
end