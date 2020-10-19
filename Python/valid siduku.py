class Solution:
    box_size = 3
    board_size = 9
    
    def rowsValid(self, board):
        # check each row
        for r in board:
            seen = set()
            for item in r:
                if item in seen:
                    return False
                elif item != '.':
                    seen.add(item)
        return True
    
    def colsValid(self, board):
        # check each column
        for i in range(self.board_size):
            seen = set()
            for r in board:
                if r[i] in seen:
                    return False
                elif r[i] != '.':
                    seen.add(r[i])
        return True
    
    def boxesValid(self, board):
        # check each box
        for boxx in range(0, self.board_size, self.box_size):
            for boxy in range(0, self.board_size, self.box_size):
                seen = set()
                for x in range(self.box_size):
                    row = board[boxx + x]
                    for y in range(self.box_size):
                        item = row[boxy + y]
                        if item in seen:
                            return False
                        elif item != '.':
                            seen.add(item)
        return True
    
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        return self.rowsValid(board) and self.colsValid(board) and self.boxesValid(board)
