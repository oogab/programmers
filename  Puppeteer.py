def solution(board, moves):
    answer = 0
    bucket = []
    
    for i in moves:
        i = i - 1
        j = 0
        while j < len(board):
            if board[j][i] > 0:
                bucket.append(board[j][i])
                board[j][i] = 0
                break
            j = j + 1
        
        if len(bucket) < 2:
            continue
            
        if bucket[-1] == bucket[-2]:
            bucket.pop()
            bucket.pop()
            answer = answer + 2
        
    return answer