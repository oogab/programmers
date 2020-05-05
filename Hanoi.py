answer = []

def Hanoi(n, f, b, t):
    if n == 1:
        answer.append([f,t])
        return
        
    Hanoi(n-1, f, t, b)
    answer.append([f,t])
    Hanoi(n-1, b, f, t)
        
def solution(n):
    Hanoi(n, 1, 2, 3)
    return answer