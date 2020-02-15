def solution(genres, plays):
    answer = []
    genres_plays = dict()
    total_plays = dict()

    for i in range(len(genres)):
        if(genres[i] in genres_plays) :
            total_plays[genres[i]] += plays[i]
            genres_plays[genres[i]].append((i, plays[i]))
        else :
            total_plays[genres[i]] = plays[i]
            genres_plays[genres[i]] = list()
            genres_plays[genres[i]].append((i, plays[i]))

    sort_keys = sorted(total_plays, key = lambda k : total_plays[k], reverse = True)

    for key in sort_keys :
        for _ in range(2) :
            try : 
                max_one = max(genres_plays[key], key = lambda x : (x[1], -x[0]))
                answer.append(max_one[0])
                genres_plays[key].remove(max_one)
            except : 
                continue

    return answer
