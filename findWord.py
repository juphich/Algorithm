
n = 5
board = [
 ['N','N','N','N','S']
,['N','E','E','E','N']
,['N','E','Y','E','N']
,['N','E','E','E','N']
,['N','N','N','N','N']
]

dx = (-1,-1,-1,1,1,1,0,0)
dy = (-1,0,1,-1,0,1,-1,1)

def inArea(y,x) :
    if (y >= n) or (x >=n) : return 0
    else : return 1

def hasWord(y, x, word):
    if inArea(y,x) == 0 : return 0

    if board[y][x] != word[0] : return 0

    if len(word) == 1 : return 1

    for d in range(8):
        nextY = y + dy[d]
        nextX = x + dx[d]
        if hasWord(nextY, nextX, word[1:]) : return 1

    return 0
