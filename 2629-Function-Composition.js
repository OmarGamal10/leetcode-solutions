/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    const toUse=functions.reverse();
    return function(x) {
       return toUse.reduce((acc,fn)=>{
        return fn(acc);
       },x)
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */