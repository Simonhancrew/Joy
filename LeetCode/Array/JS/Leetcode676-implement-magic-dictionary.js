var MagicDictionary = function () {
    this.rec = [];
};

/** 
 * @param {string[]} dictionary
 * @return {void}
 */
MagicDictionary.prototype.buildDict = function (dictionary) {
    this.rec = dictionary;
};

/** 
 * @param {string} searchWord
 * @return {boolean}
 */
MagicDictionary.prototype.search = function (searchWord) {
    for (const pa of this.rec) {
        if (pa.length != searchWord.length) continue;
        let diff = 0;
        for (let i = 0; i < searchWord.length; i++) {
            if (searchWord[i] != pa[i]) diff++;
            if (diff > 1) break;
        }
        if (diff == 1) return true;
    }
    return false;
};