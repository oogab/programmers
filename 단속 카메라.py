def solution(routes):
    # 도로 맨 앞에 감시카메라 설치
    routes = [[i[0], i[1]] for i in sorted(routes, key = lambda x: (x[0]))]
    result = [routes.pop(0)]
    for compare in routes:
        idx = 0
        while idx != len(result):
            # 새 차량의 진입시점 / 진출 시점이 기존 카메라 설치 범위에 있을 경우
            if (result[idx][0] <= compare[0] <= result[idx][1]) or (result[idx][0] <= compare[1] <= result[idx][1]):
                result[idx][0] = compare[0] if compare[0] > result[idx][0] else result[idx][0]
                result[idx][1] = compare[1] if compare[1] < result[idx][1] else result[idx][1]
                break
            else:
                idx += 1
                
        # 감시카메라 설치 위치를 전부 돌았지만 감지 못할 경우
        # 차량을 감시하는 새 감시카메라 설치
        if idx == len(result):
            result.append(compare)
    
    answer = len(result)
    return answer
