var promiseAll = function(functions) {
    return new Promise((resolve, reject) => {
        const results = new Array(functions.length);
        let completed = 0;
        let settled = false;

        functions.forEach((fn, index) => {
            fn()
                .then(value => {
                    if (settled) return;

                    results[index] = value;
                    completed++;

                    if (completed === functions.length) {
                        settled = true;
                        resolve(results);
                    }
                })
                .catch(error => {
                    if (settled) return;
                    settled = true;
                    reject(error);
                });
        });
    });
};

// ===== Example Test Case =====
const functions = [
    () => new Promise(resolve => setTimeout(() => resolve(5), 200))
];

promiseAll(functions)
    .then(result => console.log(result))
    .catch(error => console.error(error));
