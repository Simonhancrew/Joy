package sbgo

import (
	"math/rand"
	"strings"
)

type Codec struct {
	mp map[string]string
	pa string
}

func Constructor() Codec {
	pa := "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
	mp := make(map[string]string)
	return Codec{mp, pa}
}

func (this *Codec) getRandom(n int) string {
	res := strings.Builder{}
	for i := 0; i < n; i++ {
		res.WriteByte(this.pa[rand.Intn(62)])
	}
	return res.String()
}

// Encodes a URL to a shortened URL.
func (this *Codec) encode(longUrl string) string {
	for true {
		short_url := this.getRandom(6)
		if _, ok := this.mp[short_url]; ok {
			continue
		}
		this.mp[short_url] = longUrl
		return "http://hh.com/" + short_url
	}
	return ""
}

// Decodes a shortened URL to its original URL.
func (this *Codec) decode(shortUrl string) string {
	return this.mp[shortUrl[14:]]
}
