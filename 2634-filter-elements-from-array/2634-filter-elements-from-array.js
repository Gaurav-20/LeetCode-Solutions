/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let res = [];
    for (var i = 0; i < arr.length; i++) {
        if (fn(arr[i], i) != 0) {
            res.push(arr[i]);
        }
    }
    return res;
};