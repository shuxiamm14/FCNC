#include "common.h"
#include "fcnc_include.h"
#include "histSaver.h"
#include <sstream>

std::vector<fcncSample> getBkgSamples(TString framework){
	std::vector<fcncSample> samples;
	samples.emplace_back("smhiggs","SM Higgs",kViolet);
	samples.emplace_back("wjet","W+jets",kOrange);
	samples.emplace_back("diboson","Diboson",(enum EColor)7);
	samples.emplace_back("zll","Z#rightarrowll",kBlue);
	samples.emplace_back("ztautau","Z#rightarrow#tau#tau",kGreen);
	samples.emplace_back("others","Rare",kMagenta);
	samples.emplace_back("ttbar","t#bar{t}",kYellow);
	samples.emplace_back("ttV","t#bar{t}V",(enum EColor)((kAzure)+1));
	return samples;
}

std::vector<fcncSample> getFakeTauOrigin(){
	std::vector<fcncSample> samples;
	samples.emplace_back("real","real #tau",kBlue);
	samples.emplace_back("g_fake","gluon fake #tau",(enum EColor)41);
	samples.emplace_back("j_fake","light-jet fake #tau",(enum EColor)42);
	samples.emplace_back("b_fake","b-jets fake #tau",(enum EColor)43);
	samples.emplace_back("lep_fake","lepton fake #tau",(enum EColor)44);
	samples.emplace_back("c_fake","c-jets fake #tau",(enum EColor)45);
	samples.emplace_back("w_jet_fake","#tau_{W}",(enum EColor)46);
	samples.emplace_back("nomatch","no match fake #tau",(enum EColor)47);
	samples.emplace_back("doublefake","double fake #tau",(enum EColor)48);
	return samples;
} 

std::vector<fcncSample> getFakeLepOrigin(){
	std::vector<fcncSample> samples;
	samples.emplace_back("realLep","real lepton",kBlue);
	samples.emplace_back("chargeFlip","lepton charge flip",(enum EColor)42);
	samples.emplace_back("conversion","lepton flavor flip",(enum EColor)43);
	samples.emplace_back("nonPrompt","non-prompt lepton",(enum EColor)44);
	samples.emplace_back("otherFakeLep","fake lepton",(enum EColor)45);
	samples.emplace_back("unknownFakeLep","fake lepton",(enum EColor)46);
	samples.emplace_back("doubleFakeLep","double fake lepton",(enum EColor)47);
	return samples;
} 


std::vector<fcncSample> getSigSamples(TString framework, float BRbenchmark){
	std::vector<fcncSample> samples;
	std::stringstream ss;
	TString tmp = "";
	//ss<<"(BR=" << BRbenchmark << "%)";
	//ss>>tmp;
	double signorm = BRbenchmark*(framework == "xTFW"? 1:5);
	samples.emplace_back("fcnc_ch","#bar{t}t#rightarrowbWcH"+tmp,kRed,signorm);
	samples.emplace_back("fcnc_prod_ch","cg#rightarrowtH"+tmp,kRed,signorm);
	samples.emplace_back("tcH","tcH merged"+tmp,kRed,signorm);
	samples.emplace_back("fcnc_uh","#bar{t}t#rightarrowbWuH"+tmp,kRed,signorm);
	samples.emplace_back("fcnc_prod_uh","ug#rightarrowtH"+tmp,kRed,signorm);
	samples.emplace_back("tuH","tuH merged"+tmp,kRed,signorm);
	//samples.emplace_back("fcnc_ch_ml","#bar{t}t#rightarrowbWcH,H#rightarrowVV"+tmp,kRed,signorm);
	//samples.emplace_back("fcnc_uh_ml","#bar{t}t#rightarrowbWuH,H#rightarrowVV"+tmp,kRed,signorm);
	return samples;
}
TString translateRegion(TString &reg){
	std::string regtitle = reg.Data();
	translateRegion(regtitle);
	return regtitle.c_str();
}
void translateRegion(std::string &regtitle){
	findAndReplaceAll(regtitle,"reg1l1tau1b3j_","TTH~$\\tlhad$~");
	findAndReplaceAll(regtitle,"reg1l1tau1b2j_os","STH~$\\tlhad$~os");
	findAndReplaceAll(regtitle,"reg1l1tau1b_ss","l$\\tauhad$~ss");
	findAndReplaceAll(regtitle,"reg1l1tau1b1j_ss","l$\\tauhad$j~ss");
	findAndReplaceAll(regtitle,"reg1l1tau1b2j_ss","l$\\tauhad$2j~ss");
	findAndReplaceAll(regtitle,"reg1l1tau2b3j_","TTH~$\\tlhad$~2b~");
	findAndReplaceAll(regtitle,"reg1l1tau2b2j_","STH~$\\tlhad$~2b~");
	findAndReplaceAll(regtitle,"reg1l2tau1bnj_","$l\\thadhad$~");
	findAndReplaceAll(regtitle,"reg1l2tau2bnj_","$l\\thadhad$~2b~");
	findAndReplaceAll(regtitle,"reg2lSS1tau1bnj","2lSS~$\\tauhad$");
	findAndReplaceAll(regtitle,"_","~");
}

std::map<TString,variable*> getVariables(TString framework){
	std::map<TString,variable*> ret;
	float scale = framework == "xTFW"? 1:1./1000;

	if(framework == "xTFW"){
		ret["BDTG_train"] = new variable("BDTG_train","BDT discriminant",100,-1.,1.,"",1,10);
		ret["BDTG_test"] = new variable("BDTG_test","BDT discriminant",100,-1.,1.,"",1,10);
		ret["tau_pt_0"] = new variable("tau_pt_0","p_{T,lead-#tau}",90,40.,130.,"GeV",scale,10);
		ret["tau_pt_1"] = new variable("tau_pt_1","p_{T,sublead-#tau}",100,30.,80.,"GeV",scale,10);
		ret["etmiss"] = new variable("etmiss","E^{T}_{miss}",100,15.,115.,"GeV",scale,10);
		ret["dphitauetmiss"] = new variable("dphitauetmiss","#Delta#phi(#tau#tau,P^{T}_{miss})",60,0.,3.,"",1,6);
		ret["ttvismass"] = new variable("ttvismass","m_{#tau#tau,vis}",60,60.,120.,"GeV",scale,6);
		ret["drtautau"] = new variable("drtautau","#DeltaR(#tau,#tau)",100,0.4,3.4,"",1,10);
	    //ret["drttjmin"] = new variable("drttjmin","#DeltaR(#tau,light-jet,min)",80,0.2,4.2,"",1,8);
		//ret["drttj"] = new variable("drttj","#DeltaR(#tau,light-jet)",80,0.2,4.2,"",1,8);
		ret["drtaujmin"] = new variable("drtaujmin","#DeltaR(#tau,light-jet,min)",60,0.4,3.4,"",1,5);
        ret["phicent"] = new variable("phicent","E^{T}_{miss} centrality",60,-1.5,1.5,"",1,6);
		ret["t1mass"] = new variable("t1mass","m_{t,SM}",400,100.,500.,"GeV",scale,40);
		ret["tautaumass"] = new variable("tautaumass","m_{#tau,#tau}",100,100.,150.,"GeV",scale,10);
		ret["wmass"] = new variable("wmass","m_{W}",100,30.,530.,"GeV",scale,10);
		ret["t2mass"] = new variable("t2mass","m_{t,FCNC}",400,140.,340.,"GeV",scale,40);
		ret["tautauvispt"] = new variable("tautauvispt","P_{t,#tau#tau,vis}",100,50.,250.,"GeV",scale,10);
		ret["t2vismass"] = new variable("t2vismass","m_{t,FCNC,vis}",100,90.,290.,"GeV",scale,10);
		ret["t1vismass"] = new variable("t1vismass","m_{t,SM,vis}",100,50.,250.,"GeV",scale,10);
		ret["x1fit"] = new variable("x1fit","E_{vis-#tau,1}/E_{#tau,1}",70,0.3,1.,"",1,7);
		ret["x2fit"] = new variable("x2fit","E_{vis-#tau,2}/E_{#tau,2}",70,0.3,1.,"",1,7);
		//ret["tautauvispt"] = new variable("tautauvispt","P_{t,#tau#tau,vis}",100,50.,250.,"GeV",scale,5);
		//ret["t2vismass"] = new variable("t2vismass","m_{t,FCNC,vis}",100,50.,250.,"GeV",scale,5);
		//ret["t1vismass"] = new variable("t1vismass","m_{t,SM,vis}",100,50.,250.,"GeV",scale,5);
		//ret["x1fit"] = new variable("x1fit","E_{vis-#tau,1}/E_{#tau,1}",70,0.3,1.,"",1,3.5);
		//ret["x2fit"] = new variable("x2fit","E_{vis-#tau,2}/E_{#tau,2}",70,0.3,1.,"",1,3.5);
		//ret["chi2"] = new variable("chi2","#chi^{2}",100,0.,20.,"",1,5);
		ret["leading_bin"]=new variable("leading_bin","leading_bin",12, 0, 12,"",1,1);
		ret["subleading_bin"]=new variable("subleading_bin","subleading_bin",12, 0, 12,"",1,1);
		ret["chi2"] = new variable("chi2","#chi^{2}",100,0.,5.,"",1,10);
	//	ret["allmass"] = new variable("allmass","m_{all}",500,0.,1000.,"GeV",scale,50);
	//	ret["allpz"] = new variable("allpz","P_{z,all}",500,0.,1000.,"GeV",scale,50);
	}else{
		ret["BDTG_train"] = new variable("BDTG_train","BDT discriminant",100,-1.,1.,"",1,10);
		ret["BDTG_test"] = new variable("BDTG_test","BDT discriminant",100,-1.,1.,"",1,10);
		ret["chi2"] = new variable("chi2","#chi^{2}",120,0.,60.,"",1,5);
		ret["met_sigma"] = new variable("met_sigma","#sigma(E^{T}_{miss})",100,0,5,"",1,5);
		ret["tau_pt_0"] = new variable("tau_pt_0","p_{T,#tau}",100,25.,125.,"GeV",scale,10);
		ret["tau_pt_1"] = new variable("tau_pt_1","p_{T,sub-#tau}",100,25.,125.,"GeV",scale,10);
		ret["lep_pt_0"] = new variable("lep_pt_0","p_{T,l}",100,25.,125.,"GeV",scale,10);
		ret["lep_pt_1"] = new variable("lep_pt_1","p_{T,sub-l}",100,15.,115.,"GeV",scale,10);
		ret["t1mass"] = new variable("t1mass","m_{t,SM}",100,100.,300.,"GeV",scale,10);
		ret["mtw"] = new variable("mtw","m^{T}_{W}",100,0.,200.,"GeV",scale,10);
		ret["tautaumass"] = new variable("tautaumass","m_{#tau,#tau}",100,50.,250.,"GeV",scale,5);
		ret["wmass"] = new variable("wmass","m_{W}",100,0.,250.,"GeV",scale,5);
		ret["t2mass"] = new variable("t2mass","m_{t,FCNC}",200,120.,920.,"GeV",scale,5);
		ret["ttvismass"] = new variable("ttvismass","m_{#tau#tau,vis}",200,25.,225.,"GeV",scale,10);
		ret["tautauvispt"] = new variable("tautauvispt","P_{t,#tau#tau,vis}",100,0.,200.,"GeV",scale,10);
		ret["t2vismass"] = new variable("t2vismass","m_{t,FCNC,vis}",100,50.,250.,"GeV",scale,10);
		ret["t1vismass"] = new variable("t1vismass","m_{t,SM,vis}",150,40.,190.,"GeV",scale,15);
		ret["mttjmin"] = new variable("mttjmin","M(#tau#tau light-jet,min)",100,100.,300.,"GeV",scale,10);
		ret["mtaujmin"] = new variable("mtaujmin","M(#tau light-jet,min)",100,50.,250.,"GeV",scale,10);
		ret["mjjmin"] = new variable("mjjmin","M(light-jet,light-jet,min)",100,20.,200.,"GeV",scale,5);
		ret["etmiss"] = new variable("etmiss","E^{T}_{miss}",100,15.,115.,"GeV",scale,10);
		ret["x1fit"] = new variable("x1fit","E_{vis-#tau,1}/E_{#tau,1}",140,0.3,1.,"",1,7);
		ret["x2fit"] = new variable("x2fit","E_{vis-#tau,2}/E_{#tau,2}",140,0.3,1.,"",1,7);
		ret["drlbditau"] = new variable("drlbditau","#DeltaR(l+b-jet,#tau#tau)",50,0.,5.,"",1,5);
		ret["drlb"] = new variable("drlb","#DeltaR(l,b-jet)",50,0.,5.,"",1,5);
		ret["drtaub"] = new variable("drtaub","#DeltaR(#tau,b-jet)",60,0.,6.,"",1,5);
		ret["etamax"] = new variable("etamax","#eta_{#tau,max}",100,0.,2.5,"",1,10);
		ret["drltau"] = new variable("drltau","#DeltaR(l,#tau)",72,0.4,4.,"",1,8);
		ret["drtauj"] = new variable("drtauj","#DeltaR(#tau,fcnc-j)",120,0.,6.,"",1,10);
		ret["drtautau"] = new variable("drtautau","#DeltaR(#tau,#tau)",92,0.4,5.,"",1,4);
		ret["drtaujmin"] = new variable("drtaujmin","#DeltaR(#tau,light-jet,min)",60,0.4,3.4,"",1,5);
		ret["nljet"] = new variable("nljet","N_{l-jet}",10,0.,10.,"",1);
		ret["dphitauetmiss"] = new variable("dphitauetmiss","#Delta#phi(#tau#tau,P^{T}_{miss})",60,0.,3.,"",1,5);
		ret["phicent"] = new variable("phicent","E^{T}_{miss} centrality",60,-1.5,1.5,"",1,5);
		ret["mll"] = new variable("mll","m_{ll}",100,15,215,"GeV",scale,10);

    	//ret["bpt"] = new variable("bpt","p_{T,b}",10,25.,125.,"GeV",scale);
    	//ret["ljetpt"] = new variable("ljetpt","p_{T,light-jet}",10,25.,125.,"GeV",scale);
	}
	return ret;
}

observable measure(std::vector<observable> &data){
	double a = 0, b = 0, c = 0;
	double tmpsigma2 = 0;
	observable ret;
	for(auto x : data){
		tmpsigma2 = pow(x.error,2);
		a+=1/tmpsigma2;
		b+=x.nominal/tmpsigma2;
		c+=pow(x.nominal,2)/tmpsigma2;
	}
	ret.nominal = b/a;
	double minChi2 = 1;
	for(auto x : data){
		minChi2 += pow(ret.nominal-x.nominal,2)/pow(x.error,2);
	}
	b*=2;
	ret.error = sqrt(pow(b,2)-4*a*(c-minChi2))/2/a;  //stat uncertainty calculated through likelihood method

	double scdmmt = 0;
	for(auto x : data){
		scdmmt += pow(ret.nominal-x.nominal,2)/pow(x.error,2);  //second moment calculation
	}
	ret.error = ret.errordown = rms(sqrt(scdmmt/a),ret.error); //stat + systematics
	return ret;
}
