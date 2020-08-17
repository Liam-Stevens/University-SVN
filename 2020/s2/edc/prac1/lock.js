var status = "OPEN"
var code = ""
var savedCode = ""
var time = 0
var timerEnabled = false

function tick()
{
    if (timerEnabled)
    {
        time = time + 1
    }

    if (time >= 100)
    {
        resetCode()
        resetTimer()
    }
}

function addNum(num)
{
    if (code.length < 4)
    {
        code = code + num
    }
    setDisplay(code)
    timerEnabled = true
}

function resetCode()
{
    code = ""
    setDisplay(status)
}

function resetTimer()
{
    timerEnabled = false
    time = 0
}

function button1()
{
    addNum(1)
}

function button2()
{
    addNum(2)
}

function button3()
{
    addNum(3)
}

function button4()
{
    addNum(4)
}

function button5()
{
    addNum(5)
}

function button6()
{
    addNum(6)
}

function button7()
{
    addNum(7)
}

function button8()
{
    addNum(8)
}

function button9()
{
    addNum(9)
}

function buttonStar()
{
    resetCode()
    resetTimer()
}

function button0()
{
    addNum(0)
}

function buttonHash()
{
    if (code.length == 4 && status == "OPEN")
    {
        savedCode = code
        code = ""
        status = "LOCKED"
        setDisplay(status)
        setLock(true)
        resetTimer()
    }

    if (code.length == 4 && status == "LOCKED")
    {
        if (code === savedCode)
        {
            savedCode = ""
            code = ""
            status = "OPEN"
            setDisplay(status)
            setLock(false)
            resetTimer()
        }
        else
        {
            resetCode()
            resetTimer()
        }
    }
}

window.addEventListener("load", function()
{
    setDisplay(status)
    setLock(false)
})
