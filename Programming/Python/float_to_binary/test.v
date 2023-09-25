module abc;
    real val;
    reg[63:0] valb;

    initial
		begin
            valb = 64'b1100000001100000000000000000000000000000000000000000000000000000;
            $display("Input val = %b",valb);
            val = $bitstoreal(valb);
            $display("realtobits %f",val);
            $display("---------------------");
        end
endmodule