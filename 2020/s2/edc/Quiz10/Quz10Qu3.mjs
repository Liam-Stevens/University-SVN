import pkg from 'rx/dist/rx.all.js';
const { Rx } = pkg;

var lastItem1 = null;
var lastItem2 = null;

var stream1 = [
    { value: 4, time: 1000 },
    { value: 2, time: 1500 },
    { value: 3, time: 2000 }
];

var stream2 = [
    { value: 3, time: 1000 },
    { value: 1, time: 1500 },
    { value: 0, time: 2000 }
];

// Only emits items from each stream if they're smaller than the previous emitted item in that stream
var transform1 = Rx.Observable.from(stream1)
    .filter(function (x) { 
        if (lastItem1 != null && lastItem1 > x.value)
        {
            lastItem1 = x.value;
            return true; 
        }
        lastItem1 = x.value;
        return false;
    });
    
var transform2 = Rx.Observable.from(stream2)
    .filter(function (x) {
        if (lastItem2 != null && lastItem2 > x.value) {
            lastItem2 = x.value;
            return true;
        }
        lastItem2 = x.value;
        return false
    });

// Combines the 2 streams, emitting only the the larger value of the two streams and Emits 1 item/sec, even if no new items have been received
var combine = Rx.Observable.merge(transform1, transform2).mergeMap(function (item) {
        return Rx.Observable
            .of(item.value)
            .delay(item.time);
        }).max().debounce(1000);
      
    
var subscription = combine.subscribe(
    function (x) {
        console.log('Emit: %s', x);
    });