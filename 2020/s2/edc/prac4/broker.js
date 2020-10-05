var subscriptions = [];

function emit(type)
{
    //console.log(subscriptions)
    for (let [index, subscription] of subscriptions.entries()) {
        if (subscription.name === type)
        {
            //console.log(subscription.name + " | " + type);
            subscription.handlers.forEach( function (runHandler)
            {
                runHandler();
            });
        }
    }
}

function findSub(type)
{
    for (let [index, subscription] of subscriptions.entries()) {
        if (subscription.name === type)
        {
            return subscription;
        }
    }
    return null;
}

function subscribe(type,handler)
{
    var subscription = findSub(type);
    if (subscription == null)
    {
        subscription = { name: type, handlers: [] };
        subscriptions.push(subscription);
    }
    subscription.handlers.push(handler);
}

function unsubscribe(type,handler)
{
    var subscription = findSub(type);
    if (subscription == null)
    {
        return;
    }

    //TODO: splice the handler out

    //TODO: if the handler array is empty slice the event out
}

module.exports = { emit, subscribe, unsubscribe };
