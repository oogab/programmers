import datetime
 
def solution(lines):
    start_end_time = []
    sorted_time = []
    tmp_answer = 0
    answer = tmp_answer
    for line in lines:
        split_line = line.split()
        split_day = split_line[0].split('-')
        split_time = split_line[1].split(':')
        split_s = split_time[2].split('.')
        
        Y = int(split_day[0]); M = int(split_day[1]); D = int(split_day[2])
        h = int(split_time[0]); m = int(split_time[1])
        s = int(split_s[0]); ms = int(split_s[1])*1000
        
        end_datetime = datetime.datetime(Y,M,D,h,m,s,ms)
        
        split_processing = split_line[2][:-1].split('.')
        processing_s = int(split_processing[0])
        if len(split_processing) == 1:
            start_datetime = end_datetime - datetime.timedelta(seconds=processing_s)
        else:
            processing_ms = int(split_processing[1]) * 1000
            start_datetime = end_datetime - datetime.timedelta(seconds=processing_s) - datetime.timedelta(microseconds=processing_ms)
        start_datetime = start_datetime + datetime.timedelta(microseconds=1000)
        start_end_time.append([start_datetime,end_datetime])
        sorted_time.append(start_datetime)
        sorted_time.append(end_datetime)
    sorted_time.sort()
    
    for compare_time in sorted_time:
        compare_time_one = compare_time + datetime.timedelta(seconds=1)
        if compare_time >= start_end_time[-1][1]:
            break;
        for each in start_end_time:
            if (compare_time <= each[0])and(each[0] < compare_time_one):
                tmp_answer += 1
            elif (compare_time <= each[1])and(each[1] < compare_time_one):
                tmp_answer += 1
            elif (each[0] <= compare_time)and(compare_time_one <= each[1]):
                tmp_answer += 1
        if answer < tmp_answer:
            answer = tmp_answer
        tmp_answer = 0
    if answer == 0:
        answer += 1
    return answer
