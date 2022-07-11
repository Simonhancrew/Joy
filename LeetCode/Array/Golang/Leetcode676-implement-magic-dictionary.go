type MagicDictionary struct {
	rec []string
}

func Constructor() MagicDictionary {
	rec := []string{}
	return MagicDictionary{rec}
}

func (this *MagicDictionary) BuildDict(dictionary []string) {
	this.rec = dictionary
}

func (this *MagicDictionary) Search(searchWord string) bool {
	for _, pa := range this.rec {
		if len(pa) != len(searchWord) {
			continue
		}
		diff, n := 0, len(pa)
		for i := 0; i < n; i++ {
			if pa[i] != searchWord[i] {
				diff++
			}
			if diff > 1 {
				break
			}
		}
		if diff == 1 {
			return true
		}
	}
	return false
}
