#include "common.h"
#include "fcnc_include.h"
#include "histSaver.h"
#include <sstream>

std::vector<fcncSample> getBkgSamples(TString framework){
	std::vector<fcncSample> samples;
	samples.emplace_back("smhiggs","SM Higgs",kViolet);
	samples.emplace_back("wjet","W+jets",kOrange);
	samples.emplace_back("diboson","Diboson",(enum EColor)7);
//<<<<<<< HEAD
	samples.emplace_back("other","other",kBlue);
	samples.emplace_back("ztautau","Z#rightarrow#tau#tau",kGreen);
	if(framework=="tthML"){
		//samples.push_back(fcncSample("top","Top rare",kWhite));
		samples.emplace_back("others","Rare",kMagenta);
		samples.emplace_back("ttbar","t#bar{t}",kYellow);
		samples.emplace_back("ttV","t#bar{t}V",(enum EColor)((kAzure)+1));
	}else{
		samples.emplace_back("top","Top production",kRed);
	}
	//samples.push_back(fcncSample("othertop","Top rare",kWhite));
	//samples.push_back(fcncSample("others","Rare",kTeal));
	//samples.push_back(fcncSample("ttbar","t#bar{t}",kYellow));
	//samples.push_back(fcncSample("ttV","t#bar{t}V",kAzure));
/*=======
	samples.emplace_back("zll","Z#rightarrowll",kBlue);
	samples.emplace_back("ztautau","Z#rightarrow#tau#tau",kGreen);
	samples.emplace_back("others","Rare",kMagenta);
	samples.emplace_back("ttbar","t#bar{t}",kYellow);
	samples.emplace_back("ttV","t#bar{t}V",(enum EColor)((kAzure)+1));
>>>>>>> upstream/master
*/	return samples;
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
	samples.emplace_back("tcH","tcH merged signal"+tmp,kRed,signorm);
	samples.emplace_back("fcnc_uh","#bar{t}t#rightarrowbWuH"+tmp,kRed,signorm);
	samples.emplace_back("fcnc_prod_uh","ug#rightarrowtH"+tmp,kRed,signorm);
	samples.emplace_back("tuH","tuH merged signal"+tmp,kRed,signorm);
	//samples.emplace_back("fcnc_ch_ml","#bar{t}t#rightarrowbWcH,H#rightarrowVV"+tmp,kRed,signorm);
	//samples.emplace_back("fcnc_uh_ml","#bar{t}t#rightarrowbWuH,H#rightarrowVV"+tmp,kRed,signorm);
	return samples;
}
void translateRegion(std::string &regtitle){
	findAndReplaceAll(regtitle,"reg1l1tau1b3j_","TTH~$\\tlhad$~");
	findAndReplaceAll(regtitle,"reg1l1tau1b2j_","STH~$\\tlhad$~");
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
		ret["tau_pt_0"] = new variable("tau_pt_0","p_{T,lead-#tau}",100,40.,140.,"GeV",scale,10);
		ret["tau_pt_1"] = new variable("tau_pt_1","p_{T,sublead-#tau}",100,30.,80.,"GeV",scale,10);
		ret["etmiss"] = new variable("etmiss","E^{T}_{miss}",100,15.,115.,"GeV",scale,10);
		ret["dphitauetmiss"] = new variable("dphitauetmiss","#Delta#phi(#tau#tau,P^{T}_{miss})",60,0.,3.,"",1,6);
		ret["ttvismass"] = new variable("ttvismass","m_{#tau#tau,vis}",80,50.,130.,"GeV",scale,8);
		ret["drtautau"] = new variable("drtautau","#DeltaR(#tau,#tau)",100,0.4,3.4,"",1,10);
	      	ret["drttjmin"] = new variable("drttjmin","#DeltaR(#tau,light-jet,min)",80,0.2,4.2,"",1,8);
		//ret["drttj"] = new variable("drttj","#DeltaR(#tau,light-jet)",80,0.2,4.2,"",1,8);
                ret["phicent"] = new variable("phicent","E^{T}_{miss} centrality",60,-1.5,1.5,"",1,6);
		ret["t1mass"] = new variable("t1mass","m_{t,SM}",900,100.,1000.,"GeV",scale,90);
		ret["tautaumass"] = new variable("tautaumass","m_{#tau,#tau}",100,70.,170.,"GeV",scale,10);
		ret["wmass"] = new variable("wmass","m_{W}",100,30.,530.,"GeV",scale,10);
		ret["t2mass"] = new variable("t2mass","m_{t,FCNC}",400,100.,500.,"GeV",scale,40);
		ret["tautauvispt"] = new variable("tautauvispt","P_{t,#tau#tau,vis}",100,50.,250.,"GeV",scale,10);
		ret["t2vismass"] = new variable("t2vismass","m_{t,FCNC,vis}",100,50.,250.,"GeV",scale,10);
		ret["t1vismass"] = new variable("t1vismass","m_{t,SM,vis}",100,50.,250.,"GeV",scale,10);
		ret["x1fit"] = new variable("x1fit","E_{vis-#tau,1}/E_{#tau,1}",80,0.2,1.,"",1,8);
		ret["x2fit"] = new variable("x2fit","E_{vis-#tau,2}/E_{#tau,2}",80,0.2,1.,"",1,8);
		ret["chi2"] = new variable("chi2","#chi^2",60,-13.,17.,"",1,6);
		//ret["allmass"] = new variable("allmass","m_{all}",500,0.,1000.,"GeV",scale,50);
		//ret["allpz"] = new variable("allpz","P_{z,all}",500,0.,1000.,"GeV",scale,50);
                ret["tauvis0E"] = new variable("tauvis0E","#tau vis0-E",100,40,140,"GeV",scale,10); // taus_p4->at(0)->E();
                ret["tauvis1E"] = new variable("tauvis1E","#tau vis1-E",100,20,120,"GeV",scale,10); // tau2->E()
                ret["tau0E"] = new variable("tau0E","#tau0-E",100,40,140,"GeV",scale,10); // (*(taus_p4->at(0)) + *neutrinos_p4->at(0)).E()
                ret["tau1E"] = new variable("tau1E","#tau1-E",100,20,120,"GeV",scale,10); // (*(tau2) + *neutrinos_p4->at(1)).E()
                ret["neu0E"] = new variable("neu0E","#neu0-E",100,40,140,"GeV",scale,10); // neutrinos_p4->at(0)->E()
                ret["neu1E"] = new variable("neu1E","#neu1-E",100,20,120,"GeV",scale,10); // neutrinos_p4->at(1)->E()
                ret["njetNumber"] = new variable("njetNumber","jetmulti",5,3,8,"",1,1);
		ret["leadingJetPt"] = new variable("leadingJetPt","p_{T,lead-jet}",14,70.,210.,"GeV",scale,1);
		ret["subleadingJetPt"] = new variable("subleadingJetPt","p_{T,sublead-jet}",16,20.,180.,"GeV",scale,1);
                ret["x0"] = new variable("x0","ditau_coll_approx_x0",20,0.,2.,"",scale,1);
		ret["x1"] = new variable("x1","ditau_coll_approx_x1",20,0.,2.,"",scale,1);
		ret["ditau_jet_2_deta"] = new variable("ditau_jet_2_deta","|#eta(ll) - #eta(j_{2})|",20,0.,10.,"",scale,1);
		ret["ditau_jet_1_deta"] = new variable("ditau_jet_1_deta","|#eta(ll) - #eta(j_{1})|",20,0.,10.,"",scale,1);
		ret["ditau_jet_0_deta"] = new variable("ditau_jet_0_deta","|#eta(ll) - #eta(j_{0})|",20,0.,10.,"",scale,1);
		ret["ditau_jet_2_delta_rapidity"] = new variable("ditau_jet_2_delta_rapidity","|Y(ll) - Y(j_{2})|",20,0.,10.,"",scale,1);
		ret["ditau_jet_1_delta_rapidity"] = new variable("ditau_jet_1_delta_rapidity","|Y(ll) - Y(j_{1})|",20,0.,10.,"",scale,1);
		ret["ditau_jet_0_delta_rapidity"] = new variable("ditau_jet_0_delta_rapidity","|Y(ll) - Y(j_{0})|",20,0.,10.,"",scale,1);
		ret["ditau_rapidity"] = new variable("ditau_rapidity","ditau_rapidity",50, -2.5, 2.5,"",scale,1);
		ret["ditau_met_centrality"] = new variable("ditau_met_centrality","ditau_met_centrality",20, 0, 2,"",scale,1);
		ret["ditau_higgspt"] = new variable("ditau_higgspt","p_{T}(H)",39, 0, 390,"GeV",scale,1);
		ret["ditau_deta"] = new variable("ditau_deta","#Delta#eta(#tau, #tau)",20, 0, 2,"",scale,1);
		ret["ditau_dphi"] = new variable("ditau_dphi","#Delta#phi(#tau, #tau)",32, -3.2, 3.2,"",scale,1);
		ret["ditau_dr"] = new variable("ditau_dr","#DeltaR(#tau, #tau)",34, 0, 3.4,"",scale,1);
		ret["tau_0_rnn_score"] = new variable("tau_0_rnn_score","#tau_{0} RNN score",50, 0., 1.,"",scale,1);
		ret["tau_1_rnn_score"] = new variable("tau_1_rnn_score","#tau_{1} RNN score",50, 0., 1.,"",scale,1);
                ret["ditau_coll_approx_m"]=new variable("ditau_coll_approx_m","ditau_coll_approx_m",20, 0, 200,"GeV",scale,1);
	}else{
		ret["BDTG_train"] = new variable("BDTG_train","BDT discriminant",100,-1.,1.,"",1,10);
		ret["BDTG_test"] = new variable("BDTG_test","BDT discriminant",100,-1.,1.,"",1,10);
		ret["chi2"] = new variable("chi2","#chi^2",100,5.,55.,"",5);
		ret["tau_pt_0"] = new variable("tau_pt_0","p_{T,#tau}",100,25.,125.,"GeV",scale,10);
		ret["tau_pt_1"] = new variable("tau_pt_1","p_{T,sub-#tau}",100,25.,125.,"GeV",scale,10);
		ret["lep_pt_0"] = new variable("lep_pt_0","p_{T,l}",100,15.,115.,"GeV",scale,10);
		ret["lep_pt_1"] = new variable("lep_pt_1","p_{T,sub-l}",100,15.,115.,"GeV",scale,10);
		ret["t1mass"] = new variable("t1mass","m_{t,SM}",100,100.,300.,"GeV",scale,10);
		ret["mtw"] = new variable("mtw","m^{T}_{W}",100,0.,200.,"GeV",scale,10);
		ret["tautaumass"] = new variable("tautaumass","m_{#tau,#tau}",100,50.,250.,"GeV",scale,5);
		ret["wmass"] = new variable("wmass","m_{W}",100,0.,250.,"GeV",scale,5);
		ret["t2mass"] = new variable("t2mass","m_{t,FCNC}",150,120.,270.,"GeV",scale,5);
		ret["ttvismass"] = new variable("ttvismass","m_{#tau#tau,vis}",100,25.,125.,"GeV",scale,10);
		ret["tautauvispt"] = new variable("tautauvispt","P_{t,#tau#tau,vis}",100,0.,200.,"GeV",scale,10);
		ret["t2vismass"] = new variable("t2vismass","m_{t,FCNC,vis}",100,50.,250.,"GeV",scale,10);
		ret["t1vismass"] = new variable("t1vismass","m_{t,SM,vis}",150,40.,190.,"GeV",scale,15);
		ret["mttjmin"] = new variable("mttjmin","M(#tau#tau light-jet,min)",100,100.,300.,"GeV",scale,10);
		ret["mtaujmin"] = new variable("mtaujmin","M(#tau light-jet,min)",100,50.,250.,"GeV",scale,10);
		ret["mjjmin"] = new variable("mjjmin","M(light-jet,light-jet,min)",100,20.,200.,"GeV",scale,5);
		ret["etmiss"] = new variable("etmiss","E^{T}_{miss}",100,15.,115.,"GeV",scale,10);
		ret["x1fit"] = new variable("x1fit","E_{#nu,1}/E_{#tau,1}",100,0.,1.,"",1,10);
		ret["x2fit"] = new variable("x2fit","E_{#nu,2}/E_{#tau,2}",100,0.,1.,"",1,10);
		ret["drlbditau"] = new variable("drlbditau","#DeltaR(l+b-jet,#tau+#tau)",60,0.,6.,"",1,5);
		ret["drlb"] = new variable("drlb","#DeltaR(l,b-jet)",60,0.,6.,"",1,5);
		ret["drtaub"] = new variable("drtaub","#DeltaR(#tau,b-jet)",60,0.,6.,"",1,5);
		ret["etamax"] = new variable("etamax","#eta_{#tau,max}",100,0.,2.5,"",1,10);
		ret["drltau"] = new variable("drltau","#DeltaR(l,#tau)",72,0.4,4.,"",1,8);
		ret["drtauj"] = new variable("drtauj","#DeltaR(#tau,fcnc-j)",120,0.,6.,"",10);
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
