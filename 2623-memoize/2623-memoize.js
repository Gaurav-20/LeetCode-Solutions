/**
 * @param {Function} fn
 */
function memoize(fn) {
    let cache = new Map();
    return function(...args) {
        let inputKey = JSON.stringify(args);
        if (cache.has(inputKey)) {
            return cache.get(inputKey);
        }
        const res = fn(...args);
        cache.set(inputKey, res);
        return res;
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */