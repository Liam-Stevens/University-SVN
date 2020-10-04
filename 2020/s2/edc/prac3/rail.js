var trainNum = 0;

function newTrainEast1()
{
    if (checkSection(1))
    {
        var train = {name: "Train"+trainNum, direction: "East", blockSection: 1}
        trainNum += 1
        yard_trains.push(train)
        updateYard(yard_trains)
    }
}

function newTrainEast4()
{
    if (checkSection(4))
    {
        var train = {name: "Train"+trainNum, direction: "East", blockSection: 4}
        trainNum += 1
        yard_trains.push(train)
        updateYard(yard_trains)
    }
}

function newTrainWest8()
{
    if (checkSection(8))
    {
        var train = {name: "Train"+trainNum, direction: "West", blockSection: 8}
        trainNum += 1
        yard_trains.push(train)
        updateYard(yard_trains)
    }
}

function trainMove(train)
{
    var nextSec = nextSection(train)
    if (nextSec !== 0)
    {
        train.blockSection = nextSec
        updateYard(yard_trains)
    }
}

function removeTrain(targetTrain)
{
    for (let [index, train] of yard_trains.entries()) {
        if (train.name === targetTrain.name)
        {
            yard_trains.splice(index, 1)
            updateYard(yard_trains)
            break
        }
    }
}

function checkSection(sectionNum)
{
    for (let [index, train] of yard_trains.entries()) {
        if (train.blockSection === sectionNum)
        {
            return false
        }
    }
    return true
}

function nextSection(train)
{
    var currentSection = train.blockSection

    //East Bound Train
    if (train.direction === "East")
    {
        if (currentSection === 1)
        {
            if (checkSection(2))
            {
                return 2
            }
            else if (checkSection(6))
            {
                return 6
            }
            else if (checkSection(11))
            {
                return 11
            }
        }
        else if (currentSection === 2)
        {
            if (checkSection(3))
            {
                return 3
            }
        }
        else if (currentSection === 3)
        {
            removeTrain(train)
        }
        else if (currentSection === 4)
        {
            if (checkSection(5) && checkDeadlock())
            {
                return 5
            }
            else if (checkSection(10) && checkDeadlock())
            {
                return 10
            }
        }
        else if (currentSection === 5)
        {
            if (checkSection(6))
            {
                return 6
            }
            else if (checkSection(11))
            {
                return 11
            }
        }
        else if (currentSection === 6)
        {
            if (checkSection(3))
            {
                return 3
            }
        }
        else if (currentSection === 10)
        {
            if (checkSection(11))
            {
                return 11
            }
        }
        else if (currentSection === 11)
        {
            if (checkSection(3))
            {
                return 3
            }
        }
    }
    //West Bound Train
    else if (train.direction === "West")
    {
        if (currentSection === 5)
        {
            if (checkSection(9))
            {
                return 9
            }
        }
        else if (currentSection === 6)
        {
            if (checkSection(5))
            {
                return 5
            }
        }
        else if (currentSection === 7)
        {
            if (checkSection(6) && checkDeadlock())
            {
                return 6
            }
            else if (checkSection(11) && checkDeadlock())
            {
                return 11
            }
        }
        else if (currentSection === 8)
        {
            if (checkSection(7))
            {
                return 7
            }
            else if (checkSection(12))
            {
                return 12
            }
        }
        else if (currentSection === 9)
        {
            removeTrain(train)
        }
        else if (currentSection === 10)
        {
            if (checkSection(9))
            {
                return 9
            }
        }
        else if (currentSection === 11)
        {
            if (checkSection(10))
            {
                return 10
            }
            else if (checkSection(5))
            {
                return 5
            }
        }
        else if (currentSection === 12)
        {
            if (checkSection(11) && checkDeadlock())
            {
                return 11
            }
            else if (checkSection(13))
            {
                return 13
            }
        }
        else if (currentSection === 13)
        {
            if (checkSection(10))
            {
                return 10
            }
        }
    }

    return 0
}

function checkDeadlock()
{
    var counter = 0
    for (let [index, train] of yard_trains.entries()) {
        if (train.blockSection === 5 && train.direction == "East")
        {
            counter++
        }
        if (train.blockSection === 10 && train.direction == "East")
        {
            counter++
        }
        if (train.blockSection === 6 && train.direction == "West")
        {
            counter++
        }
        if (train.blockSection === 11 && train.direction == "West")
        {
            counter++
        }
    }
    if (counter >= 3)
    {
        return false
    }
    return true
}
