class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        st = set()
        for s in emails:
            t = []
            for i in range(len(s)):
                if s[i] == '.':
                    continue
                if s[i] == '+':
                    while s[i] != '@':
                        i += 1
                    t.append(s[i:])
                    break
                if s[i] == '@':
                    t.append(s[i:])
                    break
                t.append(s[i])
            st.add(''.join(t))
        return len(st)
