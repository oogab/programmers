numbers = []

def check(a, b):
    strike, ball = 0, 0
    
    for i in range(3):
        if a[i] == b[i]:
            strike += 1
            continue
            
        if b[i] in a:
            ball += 1
            
    return (strike, ball)

def get_cand():
    global numbers
    for i in range(100, 1000):
        num = str(i)
        if len(set(num)) == 3 and '0' not in num:
            numbers.append(num)

def solution(baseball):
    answer = 0

    get_cand()
    
    for ball in baseball:
        ball[0] = str(ball[0])
    
    for x in numbers:
        for ball in baseball:
            s, b = check(x, ball[0])
            if s != ball[1] or b != ball[2]:
                break
        else:
            answer += 1
    
    return answer
