# Method 1
select stock_name, sum(gain_loss) as capital_gain_loss from (
    select stock_name, 
        CASE
            WHEN operation = 'Buy' Then -price
            ELSE price
        END AS gain_loss
    FROM Stocks
) T GROUP BY stock_name;



# Method 2 
# select stock_name, sum(Sell) - sum(buy) as capital_gain_loss from Stocks (
#     unpivot (
#         operation
#         for (Buy, Sell)
#     )
# ) T group by stock_name;