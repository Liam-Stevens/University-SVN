/*
    SUBSCRIPTION OBJECT FORMAT
    Name: string
    Handlers: [functions]

*/
var subscriptions = [];

//Fetches the subscription with the given name
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

//Finds if a handler already exists within the subscription
function handlerExists(subscription, newHandler)
{
    for (let [index, currentHandler] of subscription.handlers.entries()) {
        if (currentHandler === newHandler)
        {
            return true;
        }
    }
    return false;
}

//Subscripe a handler to an event
function subscribe(type,handler)
{
    var subscription = findSub(type);

    //Create new subscription if one does not exist
    if (subscription === null)
    {
        subscription = { name: type, handlers: [] };
        subscriptions.push(subscription);
    }

    //Do not add if handler already exists
    if( !handlerExists(subscription, handler) )
    {
        subscription.handlers.push(handler);
    }

}

//Runs all handlers for the given event
function emit(type)
{
    var subscription = findSub(type);
    if (subscription === null)
    {
        return;
    }

    //Runs all handlers in the subscription
    subscription.handlers.forEach( function (runHandler)
    {
        runHandler();
    });
}

//Unsubscribe a handler from an event
function unsubscribe(type,handler)
{
    var subscription = findSub(type);
    if (subscription === null)
    {
        return;
    }

    //Splice the handler out
    for (let [index, currentHandler] of subscription.handlers.entries()) {
        if (currentHandler === handler)
        {
            subscription.handlers.splice(index, 1);
        }
    }

    //If the handler array is empty splice the event out
    if (subscription.handlers.length === 0)
    {
        for (let [index, currentSubscription] of subscriptions.entries()) {
            if (currentSubscription === subscription)
            {
                subscriptions.splice(index, 1);
            }
        }
    }
}

module.exports = { emit, subscribe, unsubscribe };
