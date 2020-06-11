def solution(arrangement):
    answer = 0
    bar_num = 0     # 쇠막대기의 개수를 담는 변수
    size = len(arrangement)
    i = 0
    while i < size-1:           # 알고리즘 상 i+1을 참조하기 때문에 인덱스 범위를 벗어나지 않게 -1을 해줌
        now = arrangement[i]    # 현재 arrangement의 원소값
        nxt = arrangement[i+1]  # 다음 arrangement의 원소값
        
        # now와 nxt의 조합은 4가지
        # '((', '()', ')(', '))'
        if now == '(':                  # now가 '('이고
            if nxt == '(':              # nxt가 '('일 경우
                bar_num = bar_num+1     # 새로운 쇠막대기가 추가 된것
            else:                       # nxt가 ')'일 경우
                answer = answer+bar_num # 레이저로 쇠막대기를 절단, 레이저 기준 왼쪽의 조각들 개수만큼 정답에 더해줌
        
        elif now == ')':                # now가 ')'이고
            if nxt == '(':              # nxt가 '('일 경우
                i = i+1                 # 고려사항 아님, 다음 arrangement로 넘어감
                continue
            else:                       # nxt가 ')'일 경우, 최상위 쇠막대기의 끝을 의미
                answer = answer+1       # 그 쇠막대기의 마지막 조각 하나를 정답에 더해줌
                bar_num = bar_num-1     # 쇠막대기의 마지막 조각까지 더했으므로 그 쇠막대기를 빼줌
                
        i = i+1

    return answer