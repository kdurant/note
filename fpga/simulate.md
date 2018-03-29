```verilog 
    integer code;
    integer fd;
    bfm.adc_din = '0;
    fd = $fopen("landRadarSignal.txt", "r");
    while(!$feof(fd))
    begin
        wait(bfm.trg_in);
        for(int i = 0; i < 8000; i = i + 1 )
        begin
            @ (posedge bfm.data_clk);
            code = $fscanf(fd, "%d", bfm.adc_din); 
        end
        @ (posedge bfm.data_clk);
        bfm.adc_din = '0;
    end
    bfm.adc_din = '0;
```
