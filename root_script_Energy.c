
void AnalyzeTreeEnergy()
{
   FILE *fp;
   fp=fopen("txt/SLAC_bb0n_10000_1_EnergyDeposit.txt", "w");
   if(fp == NULL) exit(-1);
   TFile *f = new TFile("SLAC_bb0n_10000_1.root");
   //fprintf(stderr, "%s\n","get here" );

   if (f == 0) {
      printf("Error: cannot open http://lcg-heppkg.web.cern.ch/lcg-heppkg/ROOT/eventdata.root!\n");
      return;
   }
   //fprintf(stderr, "%s\n","get here" );
   TTree* tree;
   f->GetObject("nEXOevents",tree);
   std::vector<float> *vpx=0;
   tree->SetBranchAddress("EnergyDeposit", &vpx);//,&bvpx);
   Long64_t numberevents = tree->GetEntries();
   UInt_t max = 0;
   for (Long64_t i=0;i<numberevents;i++){//numberevents;i++){
     tree -> GetEntry(i);
     UInt_t size = vpx->size();
     if(max<size)max = size;
     for(UInt_t j=0;j<  size ;j++){
        fprintf(fp,"%f\n",vpx->at(j));
      }
      fprintf(fp,"%s\n","seprate");
   }
   fprintf(stderr,"x get to end,%u", max);
   fclose(fp);




   return 0;

}
