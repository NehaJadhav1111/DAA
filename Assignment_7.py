
def is_safe(board, row, col):
    
    for i in range(row):
        if board[i][col] == 1:
            return False

    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    for i, j in zip(range(row, -1, -1), range(col, len(board))):
        if board[i][j] == 1:
            return False

    return True

def solve_queen(board, row):
    n = len(board)

    if row >= n:
        return True

    for col in range(n):
        if is_safe(board, row, col):
          
            board[row][col] = 1

            if solve_queen(board, row + 1):
                return True

            board[row][col] = 0

    return False

def print_board(board):
    for row in board:
        print(" ".join("Q" if x == 1 else "." for x in row))
    print("\n")

def solve_n_queen(n):
   
    board = [[0 for _ in range(n)] for _ in range(n)]

    if solve_queen(board, 0):
        print("Final {}-Queen Matrix:".format(n))
        print_board(board)
    else:
        print("Solution does not exist for {} queens.".format(n))

n = int(input("Enter the number of queens (n): "))
solve_n_queen(n)