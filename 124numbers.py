"""
표현 가능한 숫자가 1, 2, 4 3가지 뿐이므로 3진법의 관점으로 접근해야 한다.
하지만 0의 개념이 없기 때문에 3으로 나눈 나머지가 0인 경우를 다르게 바꾸어야 한다.
Ex) 15 == 3*5+0 => 3*4+3
따라서 나머지가 0일 경우 몫을 하나 줄이고 나머지를 3으로 만들어야 한다.
+ 5/2 => 2.5 python3에서 정수 나눗셈을 해도 알아서 실수로 바꾼다.
  5//2 => 2 '//'표현을 처음 알았다.
"""
def solution(n):
    answer = ''
    
    while n > 0:        # n이 0이하의 값이면 프로그램 종료
        if n%3==0:      # 124 나라에는 0 개념이 없기에 나머지에 0이 있으면 안됨
            rest=3      # n을 3으로 나눈 나머지가 0일 경우 3으로 바꾼다
            n = n//3    # n을 3으로 나눈 몫을 다시 n에 저장
            n -= 1      # n을 1줄여야 한다.
        else:           # n을 3으로 나눈 나머지가 0이 아닐 경우
            rest = n%3  # n을 3으로 나눈 나머지 저장
            n = n//3    # n을 3으로 나눈 몫을 다시 n에 저장
            
        if rest == 1:       # 나머지가 1일 경우
            answer += '1'   # 정답에 문자 '1'추가
        elif rest == 2:     # 나머지가 2일 경우
            answer += '2'   # 정답에 문자 '2'추가
        else:               # 나머지가 3일 경우
            answer += '4'   # 정답에 문자 '4'추가
        
    return answer[::-1]     # 지금까지 저장된 answer을 역으로 출력해야 맞는 정답이다.
"""
[A:B:C] : index A 부터 index B 까지 C의 간격으로 배열을 만들어라.
Ex)
>> arr = range(10)
>> arr [0,1,2,3,4,5,6,7,8,9]
>> arr[::2] # 처음부터 끝까지 두 칸 간격으로 [0,2,4,6,8]
>> arr[1::2] # index 1 부터 끝까지 두 칸 간격으로 [1,3,5,7,9]
>> arr[::-1] # 처음부터 끝까지 -1칸 간격으로 ( == 역순으로) [9,8,7,6,5,4,3,2,1,0]
>> arr[::-2] # 처음부터 끝까지 -2칸 간격으로 ( == 역순, 두 칸 간격으로) [9,7,5,3,1]
>> arr[3::-1] # index 3 부터 끝까지 -1칸 간격으로 ( == 역순으로) [3,2,1,0]
>> arr[1:6:2] # index 1 부터 index 6 까지 두 칸 간격으로 [1,3,5]
"""