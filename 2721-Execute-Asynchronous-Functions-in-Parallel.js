/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
 // a very very good question
var promiseAll = function(functions) {
    return new Promise((resolve,reject)=>{
        let completed=0;
        const ans=[];
        functions.forEach((fn,i)=>{
            fn().then(res=>{
                ans[i]=res;
                completed++;
                if(completed===functions.length)
                    resolve(ans);
            }).catch(err=>reject(err));
        })
    })
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */