void CBOAmplFitOptions_S12()
{
//=========Macro generated from canvas: c1/c1
//=========  (Fri Sep 21 12:03:05 2018) by ROOT version 6.12/04
   TCanvas *c1 = new TCanvas("c1", "c1",10,32,700,500);
   c1->Range(-62.5,-1.875,562.5,16.875);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   Double_t _fx1001[56] = { 7.297864, 16.23402, 25.17018, 34.10634, 43.0425, 51.97866, 60.91482, 69.85098, 78.78714, 87.7233, 96.65946, 105.5956, 114.5318, 123.4679, 132.4041, 141.3403, 150.2764, 159.2126, 168.1487, 177.0849, 186.0211, 194.9572, 203.8934, 212.8295, 221.7657, 230.7019, 239.638, 248.5742, 257.5103, 266.4465, 275.3827, 284.3188, 293.255, 302.1911, 311.1273, 320.0635, 328.9996, 337.9358, 346.8719, 355.8081, 364.7443, 373.6804, 382.6166, 391.5527, 400.4889, 409.4251, 418.3612, 427.2974, 436.2335, 445.1697, 454.1059, 463.042, 471.9782, 480.9143, 489.8505, 498.7867};
   Double_t _fy1001[56] = { 11.26187, 9.960874, 10.37475, 10.10477, 10.29611, 10.18015, 9.788981, 9.484641, 9.129033, 8.928721, 8.744666, 8.31232, 8.00231, 7.858021, 7.505768, 7.382984, 7.148508, 6.831708, 6.632526, 6.37545, 6.344753, 5.991827, 5.941709, 5.895797, 5.547034, 5.541749, 5.409855, 4.996633, 4.932256, 4.562057, 4.574817, 4.556136, 4.61057, 4.610775, 4.479185, 3.949547, 4.190754, 3.976074, 3.63532, 3.676465, 3.623757, 3.415037, 3.375466, 3.684564, 4.196833, 3.40639, 4.095519, 3.26309, 3.298525, 3.624429, 3.77234, 2.979774, 2.914627, 3.630715, 4.14184, 3.079183};
   Double_t _fex1001[56] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
   Double_t _fey1001[56] = { 0.01607276, 0.01630164, 0.0175024, 0.01908579, 0.02060461, 0.02200231, 0.0245319, 0.02557588, 0.02860921, 0.03057585, 0.03244257, 0.03652927, 0.03794742, 0.04142153, 0.0455384, 0.04678559, 0.05173076, 0.05576715, 0.05790608, 0.06504316, 0.06782751, 0.07245959, 0.0801401, 0.08263579, 0.08940322, 0.09780819, 0.1018746, 0.1107218, 0.122091, 0.1260877, 0.139014, 0.1493701, 0.1546769, 0.1713234, 0.1829697, 0.1908445, 0.2102625, 0.2208297, 0.236977, 0.2615482, 0.2729527, 0.2873288, 0.3203959, 0.3282163, 0.3527676, 0.3888468, 0.4124738, 0.4375375, 0.4784527, 0.4817631, 0.5379487, 0.5770408, 0.5824674, 0.6443905, 0.6898062, 0.8892262};
   TGraphErrors *gre = new TGraphErrors(56,_fx1001,_fy1001,_fex1001,_fey1001);
   gre->SetName("");
   gre->SetTitle(";Time [us];CBO Amplitude [mm]");
   gre->SetFillStyle(1000);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0.5);
   gre->GetXaxis()->SetLimits(0,500);
   gre->GetYaxis()->SetRangeUser(0,13);
   gre->Draw("AP");

   // Exponential with no offset
   TF1 *amplFuncExp = new TF1("amplFuncExp","[0]*exp(-x/[1])",60,500);
   amplFuncExp->SetLineColor(2);
   amplFuncExp->SetLineWidth(1);
   amplFuncExp->SetParameter(0,11.7306);
   amplFuncExp->SetParameter(1,308.67);
   gre->Fit(amplFuncExp,"R");
   amplFuncExp->Draw("SAME");
   
   // With constant offset
   TF1 *amplFuncExpConst = new TF1("amplFuncExpConst","[0]*exp(-x/[1])+[2]",60,500);
   amplFuncExpConst->SetLineColor(kSpring-1);
   amplFuncExpConst->SetLineWidth(1);
   amplFuncExpConst->SetParameter(0,11.7306);
   amplFuncExpConst->SetParameter(0,10.7546);
   amplFuncExpConst->SetParameter(1,219.92);
   amplFuncExpConst->SetParameter(2,1.67);
   gre->Fit(amplFuncExpConst,"R");
   amplFuncExpConst->Draw("SAME");
   
   // Cosine modulation of amplitude
   TF1 *amplFuncCos = new TF1("amplFuncCos","[0]*exp(-x/[1])*(1+[2]*cos(x/[3]+[4]))",60,500);
   amplFuncCos->SetLineColor(4);
   amplFuncCos->SetLineWidth(1);
   amplFuncCos->SetParameter(0,10.5882);
   amplFuncCos->SetParameter(1,409.24);
   amplFuncCos->SetParameter(2,0.135);
   amplFuncCos->SetParameter(3,114.5);
   amplFuncCos->SetParameter(4,0.482);
   amplFuncCos->SetNpx(10000);
   gre->Fit(amplFuncCos,"R");
   amplFuncCos->Draw("SAME");

   // Gaussian fit - this really doesn't work
   // TF1 *amplFuncGauss = new TF1("amplFuncGauss","[0]*TMath::Gaus(x,0,[1])+[2]",60,500);
   // amplFuncGauss->SetLineColor(6);
   // amplFuncGauss->SetLineWidth(1);
   // amplFuncGauss->SetParameter(0,10.5882);
   // amplFuncGauss->SetParameter(1,200);
   // amplFuncGauss->SetParameter(2,2);
   // amplFuncGauss->SetNpx(10000);
   // gre->Fit(amplFuncGauss,"R");
   // amplFuncGauss->Draw("SAME");

   TLegend* leg = new TLegend(0.26,0.70,0.89,0.89);
   leg->SetNColumns(2);
   leg->SetColumnSeparation(-0.1);
   leg->SetBorderSize(0);
   leg->AddEntry(amplFuncExp,"Ae^{-t/#tau}","l");
   leg->AddEntry(amplFuncExp,Form("#chi^{2}/ndf = %.2f / %d",amplFuncExp->GetChisquare(), amplFuncExp->GetNDF()),"");
   leg->AddEntry(amplFuncExpConst,"Ae^{-t/#tau} + C","l");
   leg->AddEntry(amplFuncExpConst,Form("#chi^{2}/ndf = %.2f / %d",amplFuncExpConst->GetChisquare(), amplFuncExpConst->GetNDF()),"");
   leg->AddEntry(amplFuncCos,"Ae^{-t/#tau}(1+Bcos(2#pit/T - #phi))","l");
   leg->AddEntry(amplFuncCos,Form("#chi^{2}/ndf = %.2f / %d",amplFuncCos->GetChisquare(), amplFuncCos->GetNDF()),"");
   leg->Draw();
   
}
