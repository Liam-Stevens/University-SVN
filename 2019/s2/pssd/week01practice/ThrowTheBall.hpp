class ThrowTheBall
{
    public:
    int timesThrown(int N, int M, int L)
    {
        int passes = 0;
        int people[N];
        for (int i=0; i < N; i++)
        {
            people[i] = 0;
        }

        //Simulate
        int ballLocation = 0;
        people[0]++;
        while(true)
        {
            if(people[ballLocation] == M)
            {
                break;
            } else {
                if(people[ballLocation] % 2 == 0)
                {
                    ballLocation = ballLocation + L;
                } else {
                    ballLocation = ballLocation - L;
                }

                while(ballLocation >= N)
                {
                    ballLocation = ballLocation - N;
                }
                while(ballLocation < 0)
                {
                    ballLocation = ballLocation + N;
                }

                passes++;
                people[ballLocation]++;
            }
        }

        return passes;
    }
};
