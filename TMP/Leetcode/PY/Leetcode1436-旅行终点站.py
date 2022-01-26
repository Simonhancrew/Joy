from typing import List

class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        out = {path[0] for path in paths}
        # 内层是一个迭代器
        return next(path[1] for path in paths if path[1] not in out)